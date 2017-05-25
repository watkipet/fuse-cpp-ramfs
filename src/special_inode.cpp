/** @file special_inode.cpp
 *  @copyright 2016 Peter Watkins. All rights reserved.
 */

#include <cstdio>
#include <cerrno>
#include <string>
#include <map>
#ifdef __APPLE__
#include <osxfuse/fuse/fuse_lowlevel.h>
#else
#include <fuse/fuse_lowlevel.h>
#endif

#include "inode.hpp"
#include "special_inode.hpp"

SpecialInode::SpecialInode(enum SpecialInodeTypes type) :
m_type(type) { }

//SpecialInode::~SpecialInode() {}


enum SpecialInodeTypes SpecialInode::Type() {
    return m_type;
}

int SpecialInode::WriteAndReply(fuse_req_t req, const char *buf, size_t size, off_t off) {
    return fuse_reply_err(req, ENOENT);
}

int SpecialInode::ReadAndReply(fuse_req_t req, size_t size, off_t off) {
    return fuse_reply_err(req, ENOENT);
}