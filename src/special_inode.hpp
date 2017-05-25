/** @file special_inode.hpp
 *  @copyright 2016 Peter Watkins. All rights reserved.
 */

#ifndef special_inode_hpp
#define special_inode_hpp

enum SpecialInodeTypes {
    SPECIAL_INODE_TYPE_NO_BLOCK
};

class SpecialInode : public Inode {
private:
    enum SpecialInodeTypes m_type;
public:
    SpecialInode(enum SpecialInodeTypes type);
    ~SpecialInode() {};
    
    int WriteAndReply(fuse_req_t req, const char *buf, size_t size, off_t off);
    
    int ReadAndReply(fuse_req_t req, size_t size, off_t off);
    
    enum SpecialInodeTypes Type();
};

#endif /* special_inode_hpp */
