struct bg_struct {
	int bg_block_bitmap;//starting block address of block bitmap
	int bg_inode_bitmap;//starting block address of inode bitmap
	int bg_inode_table;//starting block address of inode table
	short int bg_free_blocks_count;//number of unallocated blocks in group
	short int bg_free_inodes_count;//number of unallocated inodes in group
	short int bg_used_dirs_count;//number of directories in gdroup
	short int bg_pad;
	int bg_reserved[3];
};
