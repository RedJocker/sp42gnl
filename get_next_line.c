/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:17:35 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/27 20:30:49 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buffer_flush(t_buffer *buffer, t_stringbuilder builder)
{
	while (buffer->is_init && builder && buffer->i < buffer->char_read)
	{
		builder = stringbuilder_addchar(builder, buffer->arr[buffer->i]);
		if (buffer->arr[buffer->i++] == '\n')
			break ;
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	t_stringbuilder	builder;

	builder = stringbuilder_new();
	while (builder && (buffer.char_read > 0 || !buffer.is_init))
	{
		buffer_flush(&buffer, builder);
		if (buffer.i >= buffer.char_read || !buffer.is_init)
		{
			buffer.is_init = 1;
			buffer.i = 0;
			buffer.char_read = read(fd, buffer.arr, BUFFER_SIZE);
		}
		else
			break ;
	}
	if (!builder)
		return (NULL);
	if (buffer.char_read < 0 || stringbuilder_isempty(builder))
	{
		stringbuilder_destroy(builder);
		return (NULL);
	}
	return (stringbuilder_build(builder));
}

/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	const char *path = "./abc.txt";
	int fd = open(path, O_RDONLY);
	//int fd = 10;
	char *str;

	printf("\n==START==\n");
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	printf("==END==\n");
	return (0);
}
*/ 
