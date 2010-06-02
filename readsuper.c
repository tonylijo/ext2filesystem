#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include"superblock.h"
int get_s_inodes_count(char *buf)
{
	return (buf[3]<<24)|(buf[2]<<16)|(buf[1]<<8)|buf[0];
}
int get_s_block_count(char *buf)
{
	return (buf[7]<<24)|(buf[6]<<16)|(buf[5]<<8)|buf[4];
}
int get_s_r_blocks_count(char *buf)
{
	return (buf[11]<<24)|(buf[10]<<16)|(buf[9]<<8)|buf[8];
}
int get_s_free_blocks_count(char *buf)
{
	return (buf[15]<<24)|(buf[14]<<16)|(buf[13]<<8)|buf[12];
}
int get_s_free_inode_count(char *buf)
{
	return (buf[19]<<24)|(buf[18]<<16)|(buf[17]<<8)|buf[16];
}
int get_s_first_data_block(char *buf)
{
	return (buf[23]<<24)|(buf[22]<<16)|(buf[21]<<8)|buf[20];
}
int get_s_log_block_size(char *buf)
{
	return (buf[27]<<24)|(buf[26]<<16)|(buf[25]<<8)|buf[24];
}
int get_s_log_frag_size(char *buf)
{
	return (buf[31]<<24)|(buf[30]<<16)|(buf[29]<<8)|buf[28];
}
int get_s_block_per_group(char *buf)
{
	return (buf[35]<<24)|(buf[34]<<16)|(buf[33]<<8)|buf[32];
}
int get_s_frags_per_group(char *buf)
{
	return (buf[39]<<24)|(buf[38]<<16)|(buf[37]<<8)|buf[36];
}
int get_s_inodes_per_group(char *buf)
{
	return (buf[43]<<24)|(buf[42]<<16)|(buf[41]<<8)|buf[40];
}
int get_s_mtime(char *buf)
{
	return (buf[47]<<24)|(buf[46]<<16)|(buf[45]<<8)|buf[44];
}
int get_s_wtime(char *buf)
{
	return (buf[51]<<24)|(buf[50]<<16)|(buf[49]<<8)|buf[48];
}
short int get_s_mnt_count(char *buf)
{
	return (buf[53]<<8)|buf[52];
}
short int get_s_max_mnt_count(char *buf)
{
	return (buf[55]<<8)|buf[54];
}
short int get_s_magic(char *buf)
{
	return (buf[57]<<8)|buf[56];
}
short int get_s_state(char *buf)
{
	return (buf[59]<<8)|buf[58];
}
short int get_s_errors(char *buf)
{
	return (buf[61]<<8)|buf[60];
}
short int get_s_minor_rev_level(char *buf)
{
	return (buf[63]<<8)|buf[62];
}
int get_s_lastcheck(char *buf)
{
	return (buf[67]<<24)|(buf[66]<<16)|(buf[65]<<8)|buf[64];
}
int get_s_checkinterval(char *buf)
{
	return (buf[71]<<24)|(buf[70]<<16)|(buf[69]<<8)|buf[68];
}
int get_s_creator_os(char *buf)
{
	return (buf[75]<<24)|(buf[74]<<16)|(buf[73]<<8)|buf[72];
}
int get_s_rev_level(char *buf)
{
	return (buf[79]<<24)|(buf[78]<<16)|(buf[77]<<8)|buf[76];
}
short int get_s_def_resuid(char *buf)
{
	return (buf[81]<<8)|buf[80];
}
short int get_s_def_resgid(char *buf)
{
	return (buf[83]<<8)|buf[82];
}
int get_s_first_ino(char *buf)
{
	return (buf[87]<<24)|(buf[86]<<16)|(buf[85]<<8)|buf[84];
}
short int get_s_inode_size(char *buf)
{
	return (buf[89]<<8)|buf[88];
}
struct super *readsuper(char *filename)
{
	int fd,n;
	char buf[1024];
	fd=open(filename,O_RDONLY);
	if(lseek(fd,1024,SEEK_SET) == -1)
		printf("cannot seek.\n");
	if((n=read(fd,buf,1024))<0)
		printf("some error in reading\n");
	struct super *s_block;
	s_block = malloc(sizeof(struct super));
	s_block -> s_inodes_count = get_s_inodes_count(buf);
	s_block -> s_blocks_count = get_s_inodes_count(buf);
	s_block -> s_r_blocks_count = get_s_r_blocks_count(buf);
	s_block -> s_free_blocks_count = get_s_free_blocks_count(buf);
	s_block -> s_free_inodes_count = get_s_free_inode_count(buf);
	s_block -> s_first_data_block = get_s_first_data_block(buf);
	s_block -> s_log_block_size = get_s_log_block_size(buf);
	s_block -> s_log_frag_size = get_s_log_frag_size(buf);
	s_block -> s_block_per_group = get_s_block_per_group(buf);
	s_block -> s_frags_per_group = get_s_frags_per_group(buf);
	s_block -> s_inodes_per_group = get_s_inodes_per_group(buf);
	s_block -> s_mtime = get_s_mtime(buf);
	s_block -> s_wtime = get_s_wtime(buf);
	s_block -> s_mnt_count = get_s_mnt_count(buf);
	s_block -> s_max_mnt_count = get_s_mnt_count(buf);
	s_block -> s_magic = get_s_magic(buf);
	s_block -> s_state = get_s_state(buf);
	s_block -> s_errors = get_s_errors(buf);
	s_block -> s_minor_rev_level = get_s_minor_rev_level(buf);
	s_block -> s_lastcheck = get_s_lastcheck(buf);
	s_block -> s_checkinterval = get_s_checkinterval(buf);
	s_block -> s_creator_os = get_s_creator_os(buf);
	s_block -> s_rev_level = get_s_rev_level(buf);
	s_block -> s_def_resuid = get_s_def_resuid(buf);
	s_block -> s_def_resgid = get_s_def_resgid(buf);
	s_block -> s_first_ino = get_s_first_ino(buf);
	s_block -> s_inode_size = get_s_inode_size(buf);
	return s_block;
}
