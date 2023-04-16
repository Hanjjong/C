/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:22:21 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/15 14:31:56 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

t_list	*ft_lst_get_last(t_list *backup)
{
	t_list	*current;

	current = backup;
	while (current && current->next)
		current = current->next;
	return (current);
}

int	found_newline(t_list *backup)
{
	int		i;
	t_list	*current;

	if (backup == NULL)
		return (0);
	current = ft_lst_get_last(backup);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	free_backup(t_list *backup)
{
	t_list	*current;
	t_list	*next;

	current = backup;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

void	clean_backup(t_list **backup)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = (t_list *)malloc(sizeof(t_list));
	if (backup == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*backup);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = (char *)malloc(sizeof(char)
			* ((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_backup(*backup);
	*backup = clean_node;
}
