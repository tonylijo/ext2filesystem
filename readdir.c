#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include"dirent.h"
int get_d_ino(char *buf1,int *length)
{

	return (buf1[*length+3] << 24) | (buf1[*length+2] << 16) | (buf1[*length+1] << 8) | buf1[*length];
}
short int get_d_rec_lng(char *buf1,int *length)
{

	return (buf1[*length+5] << 8) | buf1[*length+4];
}
struct d_link *appent(struct d_link *head,struct d_link *node)
{
struct d_link *tmp=head;
	if(tmp==0)
		return node;
	else {
	while(tmp->next!=0) 
		tmp=tmp->next;
		tmp->next=node;
}
	return head;
}
void display(struct d_link *head)
{
	while(head) {
	printf("inode no :%d\trecord length :%d\t filename :%s\n",head->dir->i_no,head->dir->rec_lng,head->dir->filename);
	head=head->next;
}
}
//struct d_link *readdir(int *argc)
void readdir(int argc,char *file)
{
	struct d_entry *dir2 = 0;
	struct d_link *head=0;
	char filename[256],buf[1024];
	int fd,count=0,i,n,length=0;
	fd = open(file,O_RDONLY);
	i = argc;
	if(lseek(fd,i*1024,SEEK_SET) == -1)
		printf("cannot seek.\n");
	if((n=read(fd,buf,1024)) < 0)
		printf("some error in reading");
	do{
	dir2 = malloc(sizeof(struct d_entry));
	dir2->i_no = get_d_ino(buf,&length);
	dir2->rec_lng = get_d_rec_lng(buf,&length);
	strcpy(dir2->filename,&buf[length+8]);
	length = length + dir2->rec_lng;
	struct d_link *node=malloc(sizeof(struct d_link));
	node->dir=dir2;
	node->next=0;
	head=appent(head,node);
	}while(dir2->rec_lng>0);
	display(head);
	close(fd);
	//return head;
}
