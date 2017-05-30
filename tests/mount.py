#!/usr/bin/env python
from pathlib import Path
import subprocess
import os
import sys
import time
import errno

def make_sure_path_exists(path):
    try:
        os.makedirs(path)
    except OSError as exception:
        if exception.errno != errno.EEXIST:
            raise

make_sure_path_exists('mnt/fuse-cpp-ramfs');

child = subprocess.Popen(['src/fuse-cpp-ramfs',
                          'mnt/fuse-cpp-ramfs'])

# If you unmount too soon, the mountpoint won't be available.
time.sleep(1)

if sys.platform == 'darwin':
  subprocess.run(['umount',
                  'mnt/fuse-cpp-ramfs'])
else:
  subprocess.run(['fusermount', '-u',
                  'mnt/fuse-cpp-ramfs'])

child.wait()
sys.exit(child.returncode)
