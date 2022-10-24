#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(strcmp(argv[argc-1], "-h") == 0)
	{
		printf("%s <input> <output> <sizeinkb>\n", argv[0]);

		return 0;
	}
	
	const int maxnum = atoi(argv[3]);
	int fp1;
	int fp2;
	ssize_t numsize;
	char buffer1[maxnum];
	
	fp1 = open(argv[1], O_RDONLY);
	fp2 = open(argv[2], O_WRONLY);

	while((numsize = read(fp1, buffer1, maxnum)) > 0)
	{
		write(fp2, buffer1, numsize);
	}

	return 0;
}

