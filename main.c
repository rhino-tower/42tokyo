#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd;
	int g;

	fd = open("test1.txt", O_RDONLY);
	while ((g = get_next_line(fd, &line)) > 0)
	{
		printf("%d %s\n",g, line);
		free(line);
	}
	printf("%d %s\n",g, line);
	free(line);
	close(fd);
	system("leaks a.out");
}
