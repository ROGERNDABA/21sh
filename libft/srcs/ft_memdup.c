/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:23:36 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/28 23:24:07 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memdup(const void *src, size_t len)
{
	char	*r;

	if (!(r = (char *)malloc(len)))
		return (NULL);
	return (ft_memcpy(r, src, len));
}
