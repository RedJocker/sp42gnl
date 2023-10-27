/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:19:28 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/21 01:11:22 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stringbuilder	*t_stringbuilder;

t_stringbuilder	stringbuilder_new(void);
t_stringbuilder	stringbuilder_addchar(t_stringbuilder builder, char ch);
char			*stringbuilder_build(t_stringbuilder builder);
void			stringbuilder_destroy(t_stringbuilder builder);
int				stringbuilder_isempty(t_stringbuilder builder);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*get_next_line(int fd);

#endif
