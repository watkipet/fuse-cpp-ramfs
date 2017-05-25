#!/bin/sh

set -ex

# libfuse
wget https://github.com/libfuse/libfuse/archive/fuse-3.0.2.tar.gz
tar -xzf fuse-3.0.2.tar.gz
cd fuse-3.0.2
./makeconf.sh
./configure
make
sudo make install