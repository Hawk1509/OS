#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
void main(){
	struct stat s;
	char file[50];
	printf("enter filename:");
	scanf("%s",file);
	int i=stat(file,&s);
	printf("protection mode:%o\n",s.st_mode);
	printf("size:%d bytes\n",s.st_size);
	printf("last modification time:%s",ctime(&s.st_atime));
	printf("last access time:%s",ctime(&s.st_atime));
}


/*enter filename:sample.txt
protection mode:100664
size:12 bytes
last modification time:Wed Mar 13 14:32:38 2024
last access time:Wed Mar 13 14:32:38 2024*/
