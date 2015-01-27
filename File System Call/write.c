#include <fcntl.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  

int main(int argc, char *argv[]) {
	int fd, n, len; 
	char buf[100];
	
	if (argc != 2) {
		printf("Insufficient Arguments \n");
		printf("Other Arguments Required : \n");
		printf("File Name \n");
		exit(-1);
	}

	fd = open(argv[1], O_APPEND | O_WRONLY | O_CREAT, 0644); 
	
	if (fd < 0) {
		perror(argv[1]); 
		exit(-1);
	}

	printf("Use Ctrl-D in a New Line to Exit! \n");
	printf("\n");

	while ((n = read(0, buf, sizeof(buf))) > 0) {
		len = strlen(buf); 
		write(fd, buf, len);
	}

	close(fd);

	return 0;

}