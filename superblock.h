struct super {
	int s_inodes_count;		//number of inodes in filesystem
	int s_blocks_count;		//number of blocks in filesystem
	int s_r_blocks_count;		//number of blocks reserverved to prevent filesystem from filling up
	int s_free_blocks_count;	//number of  unallocated blocks
	int s_free_inodes_count;	//number of unallocated inodes
	int s_first_data_block;		//block where block group 0 starts
	int s_log_block_size;		//block size (saved as the number of places to shift 1024 to left
	int s_log_frag_size;		//fragment size (saved as the number of bits to shift 1024 to the left
	int s_block_per_group;		//no of blocks in each block group
	int  s_frags_per_group;		//no of fragments in each block group
	int s_inodes_per_group;		//no of inodes in each block group
	int s_mtime;			//last mount time
	int s_wtime;			//last written time
	short int s_mnt_count;		//current mount count
	short int s_max_mnt_count;	//maximanm mount count
	short int s_magic;		//signature(oxef53)
	short int s_state;		//file system state 
	short int s_errors;		//error handling methord 
	short int s_minor_rev_level;	//minor version
	int s_lastcheck;		//last consistency check time
	int s_checkinterval;		//interval between forced consistency checks
	int s_creator_os;		//creator os
	int s_rev_level;		//major version
	short int s_def_resuid;		//uid that can use reserved blocks
	short int s_def_resgid;		//gid that can use reserved blocks
/*EXT2 DYNAMIC REV SPECIFIC*/
	int s_first_ino;		//first non reserved inode in the filesystem
	short int s_inode_size;		//size of each inode structure
	short int s_block_group_nr;	//block group that this superblock is part of (if back up copy)
	int s_feature_compat;		//compatable features flags
	int s_feature_incompat;		//incompatable feature flags
	int s_feature_ro_compat;	//read only feature flags
};
