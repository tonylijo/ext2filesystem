int block_size,blocks_per_group,inodes_per_group,inode_table_start;
struct super *readsuper(char *);
struct bg_struct *readbgtable(char *);
struct inode_struct *readino(int ,char *,int , int);
void readdir1(int,char *); 
