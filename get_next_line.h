/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:57:20 by scosta-j          #+#    #+#             */
/*   Updated: 2023/02/17 22:32:22 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		find_chr_index(char *str);
int		update_buffer(char *buffer);
char	*read_line(int fd, char *buffer, char *line);
char	*treat_buffer_newline(char *buffer, char *line);
#endif