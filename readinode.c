#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include"inode.h"
short int get_i_mode(char *buf)
{
	return buf[1]<<8|buf[0];
}
short int get_i_uid(char *buf)
{
	return buf[3]<<8|buf[2];
}
int get_i_size(char *buf)
{
	return buf[7]<<24|buf[6]<<16|buf[5]<<8|buf[4];
}
int get_i_atime(char *buf)
{
	return buf[11]<<24|buf[10]<<16|buf[9]<<8|buf[8];
}
int get_i_ctime(char *buf)
{
	return buf[15]<<24|buf[14]<<16|buf[13]<<8|buf[12];
}
int get_i_mtime(char *buf)
{
	return buf[19]<<24|buf[18]<<16|buf[17]<<8|buf[16];
}
int get_i_dtime(char *buf)
{
	return buf[23]<<24|buf[22]<<16|buf[21]<<8|buf[20];
}
short int get_i_gid(char *buf)
{
	return buf[25]<<8|buf[24];
}
short int get_i_links_count(char *buf)
{
	return buf[27]<<8|buf[26];
}
int get_i_blocks(char *buf)
{
	return buf[31]<<24|buf[30]<<16|buf[29]<<8|buf[28];
}
int get_i_block(int *array,char *buf)
{
	int count=40,i=0;
	while(count<100) {
		array[i++] = buf[count+3]<<24|buf[count+2]<<16|buf[count+1]<<8|buf[count];
		count=count+4;
	}
}
struct inode_struct *readino(int ino,char *filename,int block_size,int inode_table_start)
{
	int fd,n;
	char buf[1024];
	fd=open(filename,O_RDONLY);
	if(lseek(fd,(block_size*inode_table_start)+((ino-1)*128),SEEK_SET) == -1)
		printf("cannot seek.\n");
	if((n=read(fd,buf,128))<0)
		printf("some error in reading\n");
	struct inode_struct *inode;
	inode = malloc(sizeof(struct inode_struct));
	inode->i_mode=get_i_mode(buf);
	inode->i_uid=get_i_uid(buf);
	inode->i_size=get_i_size(buf);
	inode->i_atime=get_i_atime(buf);
	inode->i_ctime=get_i_ctime(buf);
	inode->i_mtime=get_i_mtime(buf);
	inode->i_dtime=get_i_dtime(buf);
	inode->i_gid=get_i_gid(buf);
	inode->i_links_count=get_i_links_count(buf);
	inode->i_blocks=get_i_blocks(buf);
	//inode->i_flags=get_i_flags(buf);
	//inode->i_osd1=get_i_osd1(buf);
	get_i_block(inode->i_block,buf);
	return inode;
}
