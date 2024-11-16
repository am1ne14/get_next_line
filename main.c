#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    // Open file or use standard input (fd = 0)
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            return (1);
        }
    }
    else
    {
        fd = 0; // Use stdin if no file is specified
    }

    // Read and print lines using get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Close file if it was opened
    if (argc == 2)
        close(fd);

    return (0);
}