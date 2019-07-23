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

int main() {
	char c;

	enable_raw_mode();
	while (1) {
		c = '\0';
		if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
			die("read");
		if (iscntrl(c))
		{
			printf("%d\r\n", c);
		}
		else
		{
			printf("%d ('%c')\r\n", c, c);
		}
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
