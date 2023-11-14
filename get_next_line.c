/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:17:35 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/14 18:58:42 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	flush_buffer(t_buffer *b, t_stringbuilder builder)
{
	while (b->i < BUFFER_SIZE && b->is_init)
	{
		if (b->arr[b->i] != '\0')
		{
			builder = stringbuilder_addchar(builder, b->arr[b->i]);
			if (b->arr[b->i] == '\n')
			{
				b->arr[b->i] = '\0';
				break ;
			}
			b->arr[b->i] = '\0';
		}
		b->i++;
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	b;
	t_stringbuilder	builder;

	b.char_read = 1;
	builder = stringbuilder_new();
	while (builder && (b.char_read > 0 || !b.is_init))
	{
		flush_buffer(&b, builder);
		if (b.i >= BUFFER_SIZE || !b.is_init)
		{
			b.char_read = read(fd, b.arr, BUFFER_SIZE);
			b.i = 0;
			b.is_init = 1;
		}
		else
			break ;
	}
	if (!builder)
		return (NULL);
	if (b.char_read < 0 || stringbuilder_isempty(builder))
	{
		stringbuilder_destroy(builder);
		return (NULL);
	}
	return (stringbuilder_build(builder));
}
