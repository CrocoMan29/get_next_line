#include "get_next_line_bonus.h"

int main ()
{
	int	fd0 = open("yassir0.txt", O_RDONLY);
	int	fd1 = open("yassir1.txt", O_RDONLY);
	int	fd2 = open("yassir2.txt", O_RDONLY);

	printf ("%s", get_next_line(fd0));
	printf ("%s", get_next_line(fd1));
	printf ("%s", get_next_line(fd2));
	printf ("%s\n", get_next_line(fd0));
	printf ("%s\n", get_next_line(fd1));
	printf ("%s\n", get_next_line(fd2));
}