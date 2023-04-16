/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:22:06 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/07 21:05:11 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
void	free_backup(t_list *backup);
t_list	*ft_lst_get_last(t_list *backup);
int		found_newline(t_list *backup);
void	free_stash(t_list *backup);
void	clean_backup(t_list **backup);

#endif