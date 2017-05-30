#!/usr/bin/env python
from pathlib import Path
from subprocess import Popen, PIPE
import os
import sys
import time
import errno


stderrExpected = 'USAGE: fuse-cpp-ramfs MOUNTPOINT'
p = Popen('src/fuse-cpp-ramfs', stdout=PIPE, stderr=PIPE)
stdout, stderr = p.communicate()

# Check for no STDOUT
if stdout:
  sys.stderr.write('STDOUT not empty\n')
  sys.exit(-1)

# Check for proper error message
stderrStr = stderr.decode().rstrip()
if stderrStr != stderrExpected:
  sys.stderr.write('Wrong stderr\n')
  sys.stderr.write('Expected {} Actual {}\n'.format(stderrExpected, stderrStr))
  sys.exit(-1)

# The exit code should've indicated a failure
if p.returncode == 0:
  sys.stderr.write('Wrong exit code\n')
  sys.stderr.write('Expected != 0 Actual {}\n'.format(p.returncode))
  sys.exit(-1)

sys.exit(0)