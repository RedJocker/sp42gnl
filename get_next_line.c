/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:17:35 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/21 01:13:49 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t			char_read;
	char			ch;
	t_stringbuilder	builder;

	char_read = 1;
	builder = stringbuilder_new();
	ch = ' ';
	while (builder && char_read > 0 && ch != '\n')
	{
		char_read = read(fd, &ch, 1);
		if (char_read > 0)
			builder = stringbuilder_addchar(builder, ch);
	}
	if (!builder)
		return (NULL);
	if (char_read < 0 || stringbuilder_isempty(builder))
	{
		stringbuilder_destroy(builder);
		return (NULL);
	}
	return (stringbuilder_build(builder));
}


#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	const char *path = "./abc.txt";
	int fd = open(path, O_RDONLY);
	//int fd = 1;
	char *str;

	printf("\n==START==\n");
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	printf("\n==END==\n");
	return (0);
}

