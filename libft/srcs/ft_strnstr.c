/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:44:53 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/22 13:48:26 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s2[0] == '\0')
		return (char *)(s1);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i + j] == s2[j])
		{
			while (s2[j] == s1[i + j] && i + j < len)
			{
				j = j + 1;
				if (s2[j] == '\0')
					return (char *)(s1 + i);
			}
		}
		i = i + 1;
	}
	return (NULL);
}
