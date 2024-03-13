//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
void main()
{
	struct stat s;
	char file[100];
	printf("Enter file name: ");
	scanf("%s", &file);
	int i = stat(file,&s);
	printf("protect mode, %o\n",s.st_mode);
	printf("Size: %d bytes\n",s.st_size);
	printf("Last modified time: %s",ctime(&s.st_atime));

	
}

