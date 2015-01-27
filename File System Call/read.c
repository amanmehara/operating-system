#include <fcntl.h>
#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]) {
	int fd, i;
	char buf[100];

	if (argc != 2) {
		printf("Insufficient Arguments \n");
		printf("Other Arguments Required : \n");
		printf("File Name \n");
		exit(-1);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1) {
		perror(argv[1]);
		exit(-1);
	}

	printf("%s : \n", argv[1]);
	printf("\n");

	while (read(fd, buf, sizeof(buf)) > 0) {
		printf("%s", buf);
	}

	close(fd);

	return 0;

}