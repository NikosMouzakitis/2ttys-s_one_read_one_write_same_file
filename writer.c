#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/* program that writes stuff in the file */
int main()
{
	FILE *fd;
	char buffer[32];
	int ifd;
	int n;
	int ch=9;
	while(1) {
		
		printf("(0- exit) (1-type) ");
		scanf("%d",&ch);
		
		if(ch == 0)
		{
			printf("exiting");
			exit(0);
			break;
		}
		fd = fopen("text","w+");

		if(fd == NULL) {
			printf("/fopen failed\n");
			exit(-1);
		}

		scanf("%s",buffer);
		n = fwrite(buffer,sizeof(char),strlen(buffer),fd);
		printf("written:  %d\n",n);
		
		fclose(fd);		
	}
	fclose(fd);
	return 0;

}