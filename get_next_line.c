/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:32:57 by scosta-j          #+#    #+#             */
/*   Updated: 2023/02/11 20:29:18 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * BUFFER_SIZE + 1 para o /0 e /n ? confirmar
 * //exceptions buffersize<0 && that condition from read
 * check if the buffer has something already 
*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];

	
	while (*buffer || )
}
