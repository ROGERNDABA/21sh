/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger <rogerndaba@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:34:00 by Roger             #+#    #+#             */
/*   Updated: 2018/07/16 14:41:20 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char *p;

	p = 0;
	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + ft_strspn(p, delim);
	p = str + ft_strcspn(str, delim);
	if (p == str)
		return (p = 0);
	if (*p)
	{
		*p = 0;
		p = p + 1;
	}
	else
		p = 0;
	return (str);
}
