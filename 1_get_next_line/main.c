#include <stdio.h>
#include "get_next_line.h"

// export MallocStackLogging=1 find leaks after unset MallocStackLogging
// if you want more info about leaks use gcc -g option
// while true; do leaks minishell; sleep 1; done;
void leak(void)
{
	system("leaks --list a.out");
}
/*int main(int argc, char const *argv[])
{
	// atexit(leak);

	char *a;
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		return 1;
	}
	for (int i = 0; i < 404040; i++)
	{
		a = get_next_line(fd);
		printf("%s", a);
		free(a);
	}
	return 0;
}*/

int main()
{
    int fd = open("./test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);

    return 0;
}
