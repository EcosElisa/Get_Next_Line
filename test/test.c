// C program to illustrate
// read system Call
#include<stdio.h>
#include <fcntl.h>
int main()
{
int fd, sz;
char *buffer = (char *) calloc(100, sizeof(char));

fd = open("tet.txt", O_RDONLY);
if (fd < 0) { perror("r1"); exit(1); }

sz = read(fd, buffer, 5);
printf("called read(% d, buffer, 5). returned that"
		" %d bytes were read.\n", fd, sz);
//c[sz] = '\0';
printf("Those bytes are as follows: % s\n", buffer);
}

