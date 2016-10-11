#!/bin/sh

. /etc/init.d/functions

PATH=/bin:/sbin:/usr/bin:/usr/sbin

create_flash_node() {
    mkdir -p /dev/flash
    for i in `grep mtd /proc/mtd | sed -e "s/ .* //" -e "s/[:,\"]/ /g"`
    do
    	if [ "mtd" = "${i%%[0-9]}" ]; then
	    node="$i"
	else
	    ln -fs /dev/$node /dev/flash/$i
	    ln -fs /dev/$node /dev/flash/`echo $i | sed "s/^nor.//"`
	fi
    done
}

create_extra_node() {
    [ -e /etc/udev/links.conf ] || return 0
    grep '^[^#]' /etc/udev/links.conf | \
	while read type name arg1; do
	    [ "$type" -a "$name" -a ! -e "/dev/$name" -a ! -L "/dev/$name" ] || continue
	    case "$type" in
		L) ln -s $arg1 /dev/$name ;;
		D) mkdir -p /dev/$name ;;
		M) mknod -m 600 /dev/$name $arg1 ;;
		*) log_warning_msg \
			"links.conf: unparseable line ($type $name $arg1)" ;;
	    esac
    done
}

echo -n "Starting udevd: "
mount -n -t tmpfs udev /dev

create_extra_node

udevd --daemon
udevtrigger &
#udevsettle --timeout=15

create_flash_node

check_status

