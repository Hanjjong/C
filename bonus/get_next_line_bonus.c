/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:21:47 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/15 17:00:51 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static void	add_to_backup(t_list **backup, char *buf, int readed)
{
	t_list	*last;
	int		i;
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = (char *)malloc(sizeof(char) * (readed + 1));
	if (!(new_node->content))
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*backup == NULL)
	{
		*backup = new_node;
		return ;
	}
	last = ft_lst_get_last(*backup);
	last->next = new_node;
}

static void	ft_read(int fd, t_list **backup, int *readed_ptr)
{
	char	*buf;

	while (!found_newline(*backup) && *readed_ptr != 0)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		*readed_ptr = (int)read(fd, buf, BUFFER_SIZE);
		if ((!(*backup) && readed_ptr == 0) && *readed_ptr != -1)
		{
			free(buf);
			return ;
		}
		buf[*readed_ptr] = '\0';
		add_to_backup(backup, buf, *readed_ptr);
		free(buf);
	}
}

static void	generate_line(char **line, t_list *backup)
{
	int	i;
	int	j;

	j = 0;
	while (backup)
	{
		i = 0;
		while (backup->content[i])
		{
			if (backup->content[i] == '\n')
			{
				j++;
				break ;
			}
			j++;
			i++;
		}
		backup = backup->next;
	}
	*line = (char *)malloc(sizeof(char) * (j + 1));
	if (!(*line))
		return ;
}

static void	extract_line(t_list *backup, char **line)
{
	int	i;
	int	j;

	if (backup == NULL)
		return ;
	generate_line(line, backup);
	if (*line == NULL)
		return ;
	j = 0;
	while (backup)
	{
		i = 0;
		while (backup->content[i])
		{
			if (backup->content[i] == '\n')
			{
				(*line)[j++] = backup->content[i];
				break ;
			}
			(*line)[j++] = backup->content[i++];
		}
		backup = backup->next;
	}
	(*line)[j] = '\0';
}

char	*get_next_line(int fd)
{
	static t_list	*backup;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	ft_read(fd, &backup, &readed);
	if (readed == -1)
	{
		clean_backup(&backup);
		return (NULL);
	}
	if (backup == NULL)
		return (0);
	extract_line(backup, &line);
	clean_backup(&backup);
	if (line[0] == '\0')
	{
		free_backup(backup);
		backup = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}


// #include <stdio.h>

// int main(void)
// {	
// 	int fd;
// 	char * line;

// 	fd = 0;
// 	fd = open("./test",O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("|%s|", line);
// 	line = get_next_line(fd);
// 	printf("|%s|", line);
// 	line = get_next_line(fd);
// 	printf("|%s|", line);
// 	line = get_next_line(fd);
// 	printf("|%s|", line);
// 	line = get_next_line(fd);
// 	printf("|%s|", line);
// 	line = get_next_line(fd);
// 	printf("|%s|", line);
// 	line = get_next_line(fd);
// 	printf("|%s|", line);
// 	return (0);
// }
