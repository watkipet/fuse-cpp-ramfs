#!/bin/sh

set -ex

# pytest and meson
sudo pip install pytest meson

# ninja
wget https://github.com/ninja-build/ninja/releases/download/v1.7.2/ninja-linux.zip
unzip ninja-linux.zip
chmod 755 ninja
sudo chown root:root ninja
sudo mv -fv ninja /usr/local/bin
ninja --version

# libfuse
wget https://github.com/libfuse/libfuse/archive/fuse-3.0.2.tar.gz
tar -xzf fuse-3.0.2.tar.gz
mkdir build-fuse
cd build-fuse
meson .. 
mesonconf -Dinstallprefix=/usr
ninja
sudo ninja install