# get_next_line

`get_next_line` reads one line at a time from a file descriptor. Each call
returns a newly allocated string containing the next line, including the
newline when one is present. At end of file, it returns the last remaining
line if there is one, then returns `NULL`.

This repository contains both versions of the project:

- Mandatory: `get_next_line.c`, `get_next_line_utils.c`, and `get_next_line.h`
- Bonus: `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, and
  `get_next_line_bonus.h`

The mandatory and bonus files both define `get_next_line`, so they must be
compiled separately.

## How it works

The mandatory version keeps a static `rest` string. This string stores data
that was read after the newline and must be returned on the next call. This
single saved pointer is for reading one file descriptor at a time; the bonus
version keeps separate state for multiple descriptors.

1. `get_next_line` allocates a buffer of `BUFFER_SIZE + 1` bytes.
2. `read_and_save` reads from the file descriptor and joins each buffer to the
   saved `rest` string.
3. Reading stops once a newline is found or `read` reaches end of file.
4. `get_full_line` copies the part before and including the newline into the
   returned line.
5. The remaining characters are duplicated back into `rest` for the next
   call.

The small utility functions implement the string work used by this flow:
`ft_strjoin`, `ft_strlen`, `ft_strdup`, and `b4_new_line` (a bounded string
copy). `is_new_line` returns the position of the first newline, or `-1` when
there is no newline.

The bonus version uses the same logic, but replaces the single static pointer
with `static char *rest[1024]`. Each file descriptor from `0` to `1023` gets
its own saved buffer, so lines can be read alternately from several open files
without mixing their contents.

`BUFFER_SIZE` defaults to `420` in both headers. It can be changed when
compiling.

## Compile

There is no Makefile in this project. Compile the mandatory version with your
own test file, for example `main.c`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line.c get_next_line_utils.c main.c -o gnl
```

For the bonus version, use only the `_bonus` files:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("input.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

The caller owns every returned line and must free it. The function accepts
standard input as file descriptor `0`; the bonus implementation rejects file
descriptors outside the range `0`–`1023`.
