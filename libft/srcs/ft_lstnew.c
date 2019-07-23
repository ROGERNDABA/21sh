/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:42:52 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/28 23:22:06 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*r;

	if (!(r = (t_list *)malloc(sizeof(*r))))
		return (NULL);
	if (content == NULL)
	{
		r->content = NULL;
		r->content_size = 0;
	}
	else
	{
		if (!(r->content = ft_memdup(content, content_size)))
		{
			free(r);
			return (NULL);
		}
		r->content_size = content_size;
	}
	return (r);
}
