#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"inode.h"
#include"superblock.h"
#include"bg.h"
#include"dirent.h"
#include"prototypes.h"
int main(int argc,char *argv[])
{
	int fd;
	struct inode_struct *ino;
	struct super *s_block=readsuper(argv[1]);
	struct bg_struct *bg=readbgtable(argv[1]);
	block_size=1024<<s_block->s_log_block_size;
	blocks_per_group=s_block->s_block_per_group;
	inodes_per_group=s_block->s_inodes_per_group;
	inode_table_start=bg->bg_inode_table;
	ino=readino(2,argv[1],block_size,inode_table_start);
	printf("inode table start:%d\tblock size:%d\n",inode_table_start,block_size);
	printf("root directories block no:%d\n",ino->i_block[0]);
	readdir(ino->i_block[0],argv[1]);

}
