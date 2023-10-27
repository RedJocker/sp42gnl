/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:19:28 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/27 20:30:20 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define DEFAULT_LINE_SIZE 90

typedef struct s_stringbuilder	*t_stringbuilder;

struct s_stringbuilder
{
	char			*str;
	unsigned int	size;
	unsigned int	capacity;
};

typedef struct s_buffer
{
	ssize_t			char_read;
	char			arr[BUFFER_SIZE];
	ssize_t			i;
	int				is_init;
}	t_buffer;

t_stringbuilder	stringbuilder_new(void);
t_stringbuilder	stringbuilder_addchar(t_stringbuilder builder, char ch);
char			*stringbuilder_build(t_stringbuilder builder);
void			stringbuilder_destroy(t_stringbuilder builder);
int				stringbuilder_isempty(t_stringbuilder builder);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*get_next_line(int fd);

#endif
