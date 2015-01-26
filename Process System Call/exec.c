#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char*argv[])
{
	pid_t pid;
	int i;

	if (argc != 3) {
		printf("Insufficient Argument \n");
		printf("Other Argument Required : \n");
		printf("Path \n");
		printf("Command \n");
		exit(-1);
	}

	switch (pid = fork())
	{
	case -1:
		printf("Process Creation Error. \n");
		exit(-1);

	case 0:
		printf("Child Starts :\n");
		i = execl(argv[1], argv[2], 0);

		if (i < 0)
		{
			perror(argv[2]);
			exit(-1);
		}

		printf("Child Terminated. \n");

	default:
		wait(NULL);
		printf("Child Terminated. \n");
	}

	return 0;
}