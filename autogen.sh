#! /bin/sh
# Regenerate the files autoconf / automake

libtoolize --force --automake

rm -f config.cache config.log
aclocal
autoheader
autoconf
automake -a
