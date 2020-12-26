#include <stdio.h>
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
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	free(line);
	/*
	printf("%d\n", get_next_line(fd, &s));
	printf("%s\n", s);
	printf("%d\n", get_next_line(fd, &s));
	printf("%s\n", s);
*/
	close(fd);
	//system("leaks a.out");
}
