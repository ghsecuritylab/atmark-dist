/* vi: set sw=4 ts=4: */
/*
 * times() for uClibc
 *
 * Copyright (C) 2000-2006 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include <sys/syscall.h>
#include <sys/times.h>

libc_hidden_proto(times)

_syscall1(clock_t, times, struct tms *, buf);
libc_hidden_def(times)
