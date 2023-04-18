/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:52:35 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/18 16:38:47 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		ft_strchr_index(char *str, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char	*dst, char	*src, size_t	dstsize);

#endif