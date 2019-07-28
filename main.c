#include <libft.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

#define CTRL_KEY(k) ((k) & 0x1f)

struct termios orig_termios;

void disable_raw_mode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void	die(const char *s) {
	perror(s);
	exit(1);
}

void	enable_raw_mode() {
	struct termios raw;


	tcgetattr(STDIN_FILENO, &orig_termios);
	atexit(disable_raw_mode);

	raw = orig_termios;
	raw.c_iflag &= ~(ICRNL | BRKINT | IXON);
	raw.c_lflag &= ~(ICANON | ECHO | IEXTEN | ISIG);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int get_line(char **line, char c)
{
    size_t    line_len;
    char    *l2;
    char    *l3;
    int        i;

    if (*line == NULL)
        return (0);
    l2 = ft_strdup(*line);
    i = -1;
    line_len = ft_strlen(*line);
    free(*line);
    l3 = (char *)malloc((sizeof(char) * line_len) + 2);
    while (l2[++i])
      l3[i] = l2[i];
    l3[line_len] = c;
    l3[line_len + 1] = '\0';
    *line = ft_strdup(l3);
    free(l3);
    free(l2);
    return (1);
}

int main() {
	char c;
	char *line;

	line = ft_strnew(0);
	enable_raw_mode();
	while (1) {
		c = '\0';
		if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
			die("read");
		// get_line(&line, c);
		ft_putchar_fd(0, c);
		if (c == 13)
		break;
			printf("%d", c);
		if (c == CTRL_KEY('q'))
			break;
	}

	// while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
	// 	// ft_putchar_fd(c, STDIN_FILENO);
	// 	if (iscntrl(c))
	// 	{
	// 		printf("%d\n", c);
	// 	}
	// 	else
	// 	{
	// 		printf("%d ('%c')\n", c, c);
	// 	}
	// }
	return 0;
}
