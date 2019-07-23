/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:45:08 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/22 13:48:26 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char		*ft_strtrim(const char *s)
{
	int		i;
	int		start;
	int		size;
	char	*tmp;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || \
				s[i] == ','))
		i += 1;
	if (i != start)
		start = i;
	size = size - 1;
	tmp = ft_strnew(size - i);
	i = 0;
	while (start + i < size && (s[size - i] == ' ' || s[size - i] == '\t' || \
				s[size - i] == '\n' \
				|| s[size - i] == ','))
		i += 1;
	tmp = ft_strsub(s, start, size - start - i + 1);
	return (tmp);
}
