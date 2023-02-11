/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:32:59 by scosta-j          #+#    #+#             */
/*   Updated: 2023/02/10 23:55:25 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//doubt is heap memory shared??
//if it is change memcpy to memmove
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = (void *) malloc(size);
	new_ptr = memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*char_dst;
	char		*char_src;

	char_src = (char *) src;
	char_dst = (char *) dest;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
	char_dst[i] = char_src[i];
	i++;
	}
	return (dest);
}
