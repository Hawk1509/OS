#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
void main(){
	 DIR *d;
	struct dirent *de;
	d=opendir(".");
	while((de=readdir(d))!=NULL)
	{
	printf("the name is:%s\n",de->d_name );
	if((de->d_type)==0)
		printf("type.File");
	else if((de->d_type)==0)
		printf("type.directory\n");
}
closedir(d);
}

/*the name is:..
the name is:sys.c
the name is:nigga
the name is:sample.txt
the name is:apple
the name is:.
the name is:sys1.c
the name is:sys2.c
the name is:a.out
*/
