/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:43:17 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/22 13:46:52 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*v_src;
	char		*v_dst;

	v_src = src;
	v_dst = dst;
	if (!len)
		return (v_dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	v_src += len;
	v_dst += len;
	while (len--)
		*--v_dst = *--v_src;
	return (dst);
}
