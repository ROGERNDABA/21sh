/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:37:53 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/23 10:41:04 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static int		ft_return_value(int v)
{
	if (v < 0)
		return (-(v));
	else
		return (v);
}

static void		ft_a(int val, int base, char *ret, int *i)
{
	char		*b;

	if (val <= -base || base <= val)
		ft_a((val / base), base, ret, i);
	b = ft_strdup("0123456789abcdef");
	ret[(*i)++] = b[ft_return_value(val % base)];
	b = NULL;
}

char			*ft_itoa_base(int val, int base)
{
	char		*ret;
	int			i;

	if (base < 2 || base > 16 || !(ret = ft_strnew(35)))
		return (NULL);
	i = 0;
	if (base == 10 && val < 0)
		ret[i++] = '-';
	ft_a(val, base, ret, &i);
	ret[i] = '\0';
	return (ret);
}
