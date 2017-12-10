#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int k;
	FILE *fd;
	char buffer[32];
	fd = fopen("text","r");
	if(fd == NULL) {
		printf("/fopen failed\n");
		exit(-1);
	}

	while(1) {
		for(k = 0; k < 16;k++)
			buffer[k] = '\0';
l1:
		if( fread(buffer,sizeof(char),16,fd) > 0)	{
			printf("%s\n",buffer);
			sleep(1);
			fclose(fd);
			fd = fopen("text","r");
			if(fd  == NULL) {
				printf("/fopen error\n");
				exit(-1);
			}
			sleep(1);
		}
		else
			goto l1;
	}

	return 0;
}
