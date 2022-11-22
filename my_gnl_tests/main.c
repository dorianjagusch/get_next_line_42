#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int fd[8];
	char *str[8] = {"bible.txt", //0
				  "empty_lines_in_between.txt",
				  "exact_length _10.txt", //2
				  "empty.txt",
				  "moby_dick.txt",
				  "one_width.txt",
				  "only__nl.txt",
				  "looooooong_line.txt"};
	int i;
	int j;

	printf("#################################\n");
	printf("\t ONE AFTER THE OTHER\n");
	printf("#################################\n");
		
	i = 5; //modify here
	j = 0;
	printf("############################\n");
	printf("\t%s\n", str[i]);
	printf("############################\n");
	fd[i] = open(str[i], O_RDONLY);
	if(fd[i] == -1)
	{
		printf("Could not open file :(\n");
		return (1);
	}
	while (j < 5)
	{
		if (printf("Line %d: \t %s", j + 1, get_next_line(fd[5])))
			j++;
	}
	if(close(fd[i]) == -1)
	{
		printf("Could not close fd %d :(\n", fd[i]);
		return (1);
	}
	printf("\nBUFFER_SIZE = %d", BUFFER_SIZE);
	return (0);
}