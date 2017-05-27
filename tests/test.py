#!/usr/bin/env python
from pathlib import Path
import subprocess
import os

rdir = Path(__file__).parents[1]

print(rdir)

os.mkdir(str(rdir/'mnt/fuse-cpp-ramfs'));

child = subprocess.Popen([str(rdir/'build/src/fuse-cpp-ramfs'),
                         str(rdir/'mnt/fuse-cpp-ramfs')])

subprocess.run(['fusermount -u',
                str(rdir/'mnt/fuse-cpp-ramfs')])

return child.returncode