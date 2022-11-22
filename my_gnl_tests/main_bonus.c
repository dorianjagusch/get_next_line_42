#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int fd[8];
	char *str[8] = {"bible.txt",
				  "empty_lines_in_between.txt",
				  "exact_length _10.txt",
				  "empty.txt",
				  "moby_dick.txt",
				  "one_width.txt",
				  "only__nl.txt",
				  "looooooong_line.txt"};
	int i;
	int j;

	printf("#################################\n");
	printf("\t BONUS: MIX AND MATCH\n");
	printf("#################################\n");
		
	j = 0;
	i = 0;
	while (i < 8)
	{
		fd[i] = open(str[i], O_RDONLY);
		if(fd[i] == -1)
		{
			printf("Could not open file :(\n");
			return (1);
		}
		i++;
	}
	while (j < 10)
	{
		i = 0;
		while (i < 8)
		{
			printf("File: %s\nLine: %d\n %s\n\n", str[i], j + 1, get_next_line(fd[i]));
			i++;
		}
		j++;
	}
	i = 0;
	while (i < 8)
	{
		if(close(fd[i]) == -1)
		{
			printf("Could not close fd %d :(\n", fd[i]);
			return (1);
		}
		i++;
	}
	printf("\nBUFFER_SIZE = %d", BUFFER_SIZE);
	return (0);
}