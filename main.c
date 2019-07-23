#include <libft.h>


#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>    /* this comes from ncurses, anyway... */

static void clear_screen(void)
{
    char buf[1024];
    char *str;

    tgetent(buf, getenv("TERM"));
    str = tgetstr("cl", NULL);
    ft_putstr_fd(str, 0);
}

int main(void)
{
    clear_screen();
	ft_putstr_fd("roger\n", 2);
    // printf("Hello World!\n");
    return (0);
}
