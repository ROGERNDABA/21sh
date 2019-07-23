/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger <rogerndaba@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:01:08 by Roger             #+#    #+#             */
/*   Updated: 2018/07/16 12:01:36 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int		ft_getchar(void)
{
	static char	buff[BUFF_SIZE_C];
	static char	*bufp;
	static int	i;

	bufp = buff;
	i = 0;
	if (i == 0)
	{
		i = read(0, buff, 1);
		bufp = buff;
	}
	if (--i >= 0)
		return (*bufp++);
	return (-1);
}
