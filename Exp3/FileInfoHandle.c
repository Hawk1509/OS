/*C program to display the following given file
a) Protection Mode
b) Size
c) Last Access Time
d) Time of Last Modification
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
void main()
{
    struct stat s;
    char file[20];
    printf("File: ");
    scanf("%s", file);
    int i = stat(file, &s);
    printf("Protection mode:%o\n", s.st_mode & 0777);
    printf("Size:%d\n", s.st_size);
    printf("Last access time:%s", ctime(&s.st_atime));
    printf("Last modification time:%s", ctime(&s.st_mtime));
}
/*Output
File: FileInfoHandle.c
Protection mode:644
Size:515
Last access time:Sun Apr 14 12:47:14 2024
Last modification time:Sun Apr 14 12:47:14 2024
*/