/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:57:17 by rmdaba            #+#    #+#             */
/*   Updated: 2018/06/06 16:57:39 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"

char			*ft_free_strjoin(char const *s1, char const *s2, int j)
{
	char	*dest;
	int		i;

	if (!(s1 && s2))
		return (NULL);
	i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if ((dest = (char *)malloc(sizeof(dest) * i + 1)) == NULL)
		return (NULL);
	dest = ft_strcpy(dest, s1);
	dest = ft_strcat(dest, s2);
	if (j == 1 || j == 3)
		free((void *)s1);
	if (j == 2 || j == 3)
		free((void *)s2);
	return (dest);
}

char			*ft_savestr(char *str, char *instr)
{
	char		*ptr;
	int			i;

	ptr = str;
	i = 0;
	while (ptr != instr)
	{
		++ptr;
		i++;
	}
	if (i == 0)
		return (ft_strdup("\0"));
	return (ft_strsub(str, 0, i));
}

int				ft_get_line(char **save, char **line)
{
	char		*tmp;

	if (ft_strchr(*save, '\n'))
	{
		*line = ft_savestr(*save, ft_strchr(*save, '\n'));
		tmp = ft_strdup(*save);
		free(*save);
		*save = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free(tmp);
		return (1);
	}
	else if (ft_strlen(*save) != 0)
	{
		*line = ft_savestr(*save, ft_strchr(*save, '\0'));
		*save = ft_strchr(*save, '\0');
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*fcontent;
	static char	*save;
	int			ret;
	int			n;

	ret = 0;
	n = 0;
	if (fd == -1 || !line || BUFF_SIZE < 1)
		return (-1);
	fcontent = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		n = 1;
		buf[ret] = '\0';
		if (fcontent == NULL)
			fcontent = ft_strdup(buf);
		else
			fcontent = ft_free_strjoin(fcontent, buf, 1);
	}
	if (n == 1)
		save = fcontent;
	if (ret == -1)
		return (-1);
	return (ft_get_line(&save, &(*line)));
}
