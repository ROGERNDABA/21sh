/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:13:59 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/19 19:14:34 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strcjoin(char const *name1, char const *name2, char c)
{
	char	*mem;

	if (!(mem = malloc(sizeof(char) *
					(ft_strlen(name1) + ft_strlen(name2) + 2))))
		return (NULL);
	ft_strcpy(mem, name1);
	ft_strncat(mem, &c, 1);
	ft_strcat(mem, name2);
	return (mem);
}
