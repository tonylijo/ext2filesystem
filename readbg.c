#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include"bg.h"
int get_bg_block_bitmap(char *buf)
{
	return (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
}
int get_bg_inode_bitmap(char *buf)
{
	return (buf[7] << 24) | (buf[6] << 16) | (buf[5] << 8) | buf[4];
}
int get_bg_inode_table(char *buf)
{
	return (buf[11] << 24) | (buf[10] << 16) | (buf[9] << 8) | buf[8];
}
short int get_bg_free_blocks_count(char *buf)
{
	return (buf[13] << 8) | buf[12];
}
short int get_bg_free_inodes_count(char *buf)
{
	return (buf[15] << 8) | buf[14];
}
short int get_bg_used_dirs_count(char *buf)
{
	return (buf[17] << 8) | buf[16];
}
struct bg_struct *readbgtable(char *filename)
{
	struct bg_struct *bg=malloc(sizeof(struct bg_struct));
	int fd,count=0,i,n;
	char buf[1024];
	fd = open(filename,O_RDONLY);
	if(lseek(fd,2*1024,SEEK_SET) == -1)
		printf("cannot seek.\n");
	if((n=read(fd,buf,1024)) < 0)
		printf("some error in reading");
	bg->bg_block_bitmap = get_bg_block_bitmap(buf);
	bg->bg_inode_bitmap = get_bg_inode_bitmap(buf);
	bg->bg_inode_table = get_bg_inode_table(buf);
	bg->bg_free_blocks_count = get_bg_free_blocks_count(buf);
	bg->bg_free_inodes_count = get_bg_free_inodes_count(buf);
	bg->bg_used_dirs_count = get_bg_used_dirs_count(buf);
	return bg;
}
