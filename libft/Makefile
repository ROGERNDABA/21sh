# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 22:58:58 by rmdaba            #+#    #+#              #
#    Updated: 2019/07/17 19:45:33 by Roger Ndaba      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

FLAGS =-Wall -Wextra -Werror

HEADER = ./../incl/libft.h

SRCS = 	ft_strlen.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
        ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strcmp.c \
		ft_strncmp.c ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
		ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
		ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strspn.c ft_strcspn.c \
		ft_strtok.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
		ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_getchar.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_itoa_base.c ft_isblank.c \
		ft_iscntrl.c ft_isgraph.c ft_islower.c ft_isspace.c ft_isupper.c \
		ft_isxdigit.c ft_str_is_alpha.c ft_str_is_lowercase.c \
		ft_str_is_numeric.c ft_str_is_printable.c ft_str_is_uppercase.c \
		ft_strcjoin.c ft_memdup.c get_next_line.c

OBJ = 	$(SRC:%.c=%.o)


all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix srcs/, $(SRCS))
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@printf "\e[32m[ ✔ ]libft library made\n"

clean:
	@rm -rf *.o
	@printf "\e[31m[ ✔ ] Libft object files removed\n\e[0m"

fclean: clean
	@rm -rf $(NAME)
	@printf "\e[33m[ ✔ ] Libft library removed\n\e[0m"

re: fclean all

.PHONY: all, clean, fclean, re
