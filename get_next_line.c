/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:32:57 by scosta-j          #+#    #+#             */
/*   Updated: 2023/02/17 11:13:54 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/**
 * BUFFER_SIZE + 1 para o /0 e /n ? confirmar
 * //exceptions buffersize<0 && that condition from read if the file exists
 * check if the buffer has something already 
*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	line = (char *) malloc(BUFFER_SIZE +1);
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (buffer[i])
		{
			buffer[i] = 0;
			i++;
		}
		return (NULL);
	}
	if (find_chr_index(buffer, 10) != -1)
		return (treat_buffer_newline(buffer, line));
	while (buffer[i])
	{
		line[i] = buffer[i];
		buffer[i] = 0;
		i++;
	}
	line[i] = '\0';
	return (read_line (fd, buffer, line));
}

char	*treat_buffer_newline(char *buffer, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (i <= find_chr_index(buffer, 10))
			line[i] = buffer[i];
		else
		{
			buffer[j] = buffer[i];
			j++;
		}
		i++;
	}
	while (buffer[j])
	{
			buffer[j] = 0;
			j++;
	}
	line[i] = '\0';
	return (line);
}

/**
 * this function reads the file until it reaches the end of it
 * or it reaches a new line character
*/
char	*read_line(int fd, char *buffer, char *line)
{
	int	nchr_read;
	int	nline_flag;

	nchr_read = 0;
	nline_flag = 0;
	while (1)
	{
		nchr_read = read (fd, buffer, BUFFER_SIZE);
		buffer[nchr_read] = '\0';
		if (nchr_read == 0)
			return (line);
		nline_flag = find_chr_index(buffer, 10);
		if (nline_flag == -1)
			line = update_line(buffer, line, BUFFER_SIZE);
		else
			return (update_line(buffer, line, nline_flag));
	}
}

/**
 * this function returns the index of the char
 * @param str its the string where the possible char might be 
 * @param c its the char that we are searching in the string 
 * but there is an exception if we want to find the '\0' the function will
 * return the string lenght
 * @returns the index where char was found or -1 if the chr isn't found
*/
int	find_chr_index(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (-1);
}

/**
 * with the help of the auxiliar index size the function updates the
 * array that is going to be printed until the new line 
 * and after that cleans the static buffer erasing the new line and
 * everthing that is before that 
 * @param size the index that marks the end of the buffer 
 * that is going to be copied to line 
 * and after that point what is going to be kept after cleaning the buffer
*/
char	*update_line(char *buffer, char *line, int size)
{
	int	i;

	i = 0;
	line = ft_strjoin(line, buffer, size);
	size++;
	while (buffer[size + i])
	{
		buffer[i] = buffer[size + i];
		i++;
	}
	while (i <= 5)
	{
		buffer[i] = '\0';
		i++;
	}
	return (line);
}

/**
 * @pre s1 must be dynamically allocated because its going to be free'd
 * acts like the realloc function but for strings returns a concatenated string 
 * @param s1 string thats going to be concatented as the suffix
 * @param s2 string thats going to be concatented as the preffix
 * @param size refers to the size of the s2 string thats going to be concatenated
*/
char	*ft_strjoin(char *s1, char *s2, int size)
{
	int		i;
	int		strindex;
	char	*str;

	i = 0;
	strindex = 0;
	str = (char *) malloc(find_chr_index(s1, 0) + find_chr_index(s2, 0) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[strindex] = s1[i];
		strindex++;
		i++;
	}
	free (s1);
	i = 0;
	while (s2[i] && i <= size)
	{
		str[strindex] = s2[i];
		strindex++;
		i++;
	}
	str[strindex] = '\0';
	return (str);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text1.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line 1: %s \n", line);
	free(line);
		line = get_next_line(fd);
	printf("line 2: %s \n", line);
	free(line);
		line = get_next_line(fd);
	printf("line 3: %s \n", line);
	free(line);
		line = get_next_line(fd);
	printf("line 4: %s \n", line);
	free(line);
		line = get_next_line(fd);
	printf("line 5: %s \n", line);
	free(line);
}