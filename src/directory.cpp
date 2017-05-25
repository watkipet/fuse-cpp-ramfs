/** @file directory.cpp
 *  @copyright 2016 Peter Watkins. All rights reserved.
 */

#include <cstdio>
#include <string>
#include <map>
#include <cerrno>
#ifdef __APPLE__
#include <osxfuse/fuse/fuse_lowlevel.h>
#else
#include <fuse/fuse_lowlevel.h>
#endif

#include "inode.hpp"
#include "directory.hpp"

using namespace std;

/**
 Returns a child inode number given the name of the child.

 @param name The child file / dir name.
 @return The child inode number if the child is found. -1 otherwise.
 */
fuse_ino_t Directory::ChildInodeNumberWithName(const string &name) {
    if (m_children.find(name) == m_children.end()) {
        return -1;
    }
    
    return m_children[name];
}


/**
 Changes the inode number of the child with the given name.

 @param name The name of the child to update.
 @param ino The new inode number.
 @return The old inode number before the change.
 */
fuse_ino_t Directory::UpdateChild(const string &name, fuse_ino_t ino) {
    fuse_ino_t ino_ret = m_children[name];
    m_children[name] = ino;
    
    // TODO: What about directory sizes? Shouldn't we increase the reported size of our dir?
    
    return ino_ret;
}

int Directory::WriteAndReply(fuse_req_t req, const char *buf, size_t size, off_t off) {
    return fuse_reply_err(req, EISDIR);
}

int Directory::ReadAndReply(fuse_req_t req, size_t size, off_t off) {
    return fuse_reply_err(req, EISDIR);
}
