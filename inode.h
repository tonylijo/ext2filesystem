struct inode_struct {
	short int i_mode; //file mode(type and permission)
	short int i_uid; //lower 16 bits of user id
	int i_size;	//lower 32 bits of size in bytes
	int i_atime;	//Access time
	int i_ctime;	//change time
	int i_mtime;	//modification time
	int i_dtime;	//deletion time
	short int i_gid;//lower 16 bits of group id
	short int i_links_count;//link count
	int i_blocks;//sector counts
	int i_flags;//flags
	int i_osd1;
	int i_block[15];
	int i_generation;
	int i_file_acl;
	int i_dir_acl;
	int i_faddr;
//	struct osd2 i_osd2;
};
//struct osd2 {
//	char l_i_frag;
//	char l_i_fsize;
//	short int reserved1;
//	short int l_i_uid_high;
//	short int l_i_gid_high;
//	int reserved2;
//};
