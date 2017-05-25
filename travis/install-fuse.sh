#!/bin/sh
set -ex
wget https://github.com/libfuse/libfuse/archive/fuse-3.0.2.tar.gz
tar -xzvf fuse-3.0.2.tar.gz
md build-fuse
cd build-fuse
meson .. 
mesonconf -Dinstallprefix=/usr
ninja
sudo ninja install