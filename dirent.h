#define MAXFILENAME 255
struct d_entry {
	int i_no;	//inode no four bytes
	short int rec_lng;	//record length
	short int lng_type;	//name length and file type 1 st byte name length 2 nd byte file type
	char filename[MAXFILENAME+1];	//file name 
};
struct d_link {
struct d_entry *dir;
struct d_link *next;
};
