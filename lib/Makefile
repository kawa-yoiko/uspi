#
# Makefile
#
# USPi - An USB driver for Raspberry Pi written in C
# Copyright (C) 2014-2018  R. Stange <rsta2@o2online.de>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

OBJS	= uspilibrary.o \
	  dwhcidevice.o dwhciregister.o dwhcixferstagedata.o \
	  usbconfigparser.o usbdevice.o usbdevicefactory.o usbendpoint.o usbrequest.o usbstandardhub.o \
	  devicenameservice.o macaddress.o usbfunction.o smsc951x.o lan7800.o string.o util.o \
	  usbmassdevice.o \
	  dwhciframeschednper.o dwhciframeschedper.o keymap.o usbkeyboard.o \
	  dwhcirootport.o usbmouse.o \
	  dwhciframeschednsplit.o usbgamepad.o usbgamepaddecoders.o synchronize.o usbstring.o usbmidi.o

libuspi.a: $(OBJS)
	@echo "  AR    $@"
	@rm -f $@
	@$(AR) cr $@ $(OBJS)

include ../Rules.mk
