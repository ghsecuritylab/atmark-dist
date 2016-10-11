#!/usr/bin/perl
use strict;

#   Copyright (C) 2010 Mauro Carvalho Chehab <mchehab@redhat.com>
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, version 2 of the License.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
# This small script parses USB dumps generated by several drivers,
# decoding USB bits.
#
# To use it, do:
# dmesg | ./parse_usb.pl
#
# Also, there are other utilities that produce similar outputs, and it
# is not hard to parse some USB analyzers log into the expected format.
#

sub type_req($)
{
	my $reqtype = shift;
	my $s;

	if ($reqtype & 0x80) {
		$s = "RD ";
	} else {
		$s = "WR ";
	}
	if (($reqtype & 0x60) == 0x20) {
		$s .= "CLAS ";
	} elsif (($reqtype & 0x60) == 0x40) {
		$s .= "VEND ";
	} elsif (($reqtype & 0x60) == 0x60) {
		$s .= "RSVD ";
	}

	if (($reqtype & 0x1f) == 0x00) {
		$s .= "DEV ";
	} elsif (($reqtype & 0x1f) == 0x01) {
		$s .= "INT ";
	} elsif (($reqtype & 0x1f) == 0x02) {
		$s .= "EP ";
	} elsif (($reqtype & 0x1f) == 0x03) {
		$s .= "OTHER ";
	} elsif (($reqtype & 0x1f) == 0x04) {
		$s .= "PORT ";
	} elsif (($reqtype & 0x1f) == 0x05) {
		$s .= "RPIPE ";
	} else {
		$s .= sprintf "RECIP 0x%02x ", $reqtype & 0x1f;
	}

	$s =~ s/\s+$//;
	return $s;
}

while (<>) {
	tr/A-F/a-f/;
	if (m/([0-9a-f].) ([0-9a-f].) ([0-9a-f].) ([0-9a-f].) ([0-9a-f].) ([0-9a-f].) ([0-9a-f].) ([0-9a-f].)[\<\>\s]+(.*)/) {
		my $reqtype = hex($1);
		my $req = hex($2);
		my $wvalue = hex("$4$3");
		my $windex = hex("$6$5");
		my $wlen = hex("$8$7");
		my $payload = $9;

		printf("%s, Req %3d, wValue: 0x%04x, wIndex 0x%04x, wlen %d: %s\n",
			type_req($reqtype), $req, $wvalue, $windex, $wlen, $payload);
	}
}
