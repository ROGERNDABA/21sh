/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:22:59 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/28 13:01:36 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static void		ft_is_neg(long *n, int *neg)
{
	if (*n < 0)
	{
		*neg = 1;
		*n = -(*n);
	}
}

char			*ft_itoa(int n)
{
	char		*res;
	long		nb;
	int			i;
	int			neg;

	neg = 0;
	i = 2;
	nb = (long)n;
	ft_is_neg(&nb, &neg);
	i = i + neg;
	while (n /= 10)
		i += 1;
	if ((res = ft_strnew(i - 1)) == NULL)
		return (NULL);
	i -= 1;
	res[i] = '\0';
	while (i > 0)
	{
		i -= 1;
		res[i] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
