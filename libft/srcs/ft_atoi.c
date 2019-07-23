/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:21:51 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/28 14:32:27 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static long		ft_chk_o(long *nbr, int neg)
{
	if (*nbr > 2147483646 && neg % 2 == 0)
		return (-1);
	if (*nbr > 2147483647 && neg % 2 == 1)
		return (0);
	else
		return (1);
}

static int		ft_check_ng(long *nbr, int neg)
{
	if (neg == 1)
		return (-(*nbr));
	else
		return (*nbr);
}

int				ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		ng;

	nbr = 0;
	ng = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i = i + 1;
	if (str[i] == '-')
		ng = 1;
	if (str[i] == '+' || str[i] == '-')
		i = i + 1;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		if (ft_chk_o(&nbr, ng) == 0 || ft_chk_o(&nbr, ng) == -1)
			return (ft_chk_o(&nbr, ng));
		nbr = nbr * 10;
		nbr = nbr + (int)str[i] - '0';
		i = i + 1;
	}
	return (ft_check_ng(&nbr, ng));
}
