#include "get_next_line.h"

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int g;

	if (argc <= 1 || MAX_FD < argc)
		printf("command line is range(1, 256)\n");
	else
	{
		for (int i = 0; i < argc - 1; i++)
		{
			puts("---------------------");
			printf("file name : %s\n", argv[i + 1]);
			fd = open(argv[i + 1], O_RDONLY);
			while ((g = get_next_line(fd, &line)) > 0)
			{
				printf("%d %s\n",g, line);
				free(line);
			}
			printf("%d %s\n",g, line);
			free(line);
			close(fd);
		}
	}
	system("leaks a.out");
}
