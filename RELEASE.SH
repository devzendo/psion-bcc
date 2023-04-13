#!/bin/sh
VER=0.04
MAINDIR=`pwd`
rm -f psion-bcc-src-?.??.tar.gz
rm -f psion-bcc-bin-?.??.tar.gz
cd ..
tar cvf /tmp/psion-bcc-src-$VER.tar psion-bcc
gzip -9 /tmp/psion-bcc-src-$VER.tar
cd /
tar cvf /tmp/psion-bcc-bin-$VER.tar /usr/bcc
gzip -9 /tmp/psion-bcc-bin-$VER.tar
mv /tmp/psion-bcc-src-$VER.tar.gz $MAINDIR
mv /tmp/psion-bcc-bin-$VER.tar.gz $MAINDIR
echo Insert MS-DOS floppy
read return
cd $MAINDIR
mcopy psion-bcc-src-$VER.tar.gz a:
mcopy psion-bcc-bin-$VER.tar.gz a:
