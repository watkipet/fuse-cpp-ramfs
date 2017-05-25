======================================================================
fuse-cpp-ramfs: An example RAM filesystem using FUSE written in C++
======================================================================

.. contents::

Quick Run
=========
::

	cd build
	cmake ../src
	make
	make install


Requirements
============
fuse-cpp-ramfs builds with CMake version 2.6 or greater.

fuse-cpp-ramfs requires the libfuse2-1.0.1 (or later) 
filesystem-in-userspace library and header files for successful 
compilation.  libfuse is available
at: 
https://github.com/libfuse/libfuse
https://osxfuse.github.io

--
Peter Watkins
19-May-2017

