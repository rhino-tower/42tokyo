#include "get_next_line.h"

int main(int argc, char **argv)
{
	char *line;
	int fd1, fd2;
	int g;

	if (argc <= 1 || MAX_FD < argc)
		printf("command line is range(1, 256)\n");
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		g = get_next_line(fd1, &line);
		printf("%d %s\n",g, line);
		free(line);
		g = get_next_line(fd2, &line);
		printf("%d %s\n",g, line);
		free(line);
		g = get_next_line(fd1, &line);
		printf("%d %s\n",g, line);
		free(line);
		g = get_next_line(fd2, &line);
		printf("%d %s\n",g, line);
		free(line);
		close(fd1);
		close(fd2);
	}
	system("leaks a.out");
}
