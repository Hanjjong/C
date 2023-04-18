/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:53:17 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/18 18:18:00 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		substr = (char *)malloc(sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (s_len - start < len)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	i = -1;
	while (++i < len)
		substr[i] = s[start++];
	substr[i] = '\0';
	return (substr);
}

static char	*ft_add(char *backup, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(backup, buf);
	if (!tmp)
	{
		free(backup);
		return (0);
	}
	free(backup);
	return (tmp);
}

static char	*ft_cut(char **backup)
{
	char	*tmp;
	char	*ret_read;
	int		i;

	i = ft_strchr_index(*backup, '\n');
	if (i == -1)
		i = ft_strchr_index(*backup, '\0');
	ret_read = ft_substr(*backup, 0, i + 1);
	if (!ret_read)
	{
		free(*backup);
		*backup = NULL;
		return (0);
	}
	tmp = *backup;
	*backup = ft_substr(*backup, i + 1, ft_strlen(*backup));
	if (!tmp)
	{	
		free(*backup);
		*backup = NULL;
		return (0);
	}
	free(tmp);
	return (ret_read);
}

int	read_check(int read, char **backup)
{
	if (read == -1 || (read == 0 && !(**backup)))
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	int			readed;

	if (!backup)
		backup = ft_strdup("");
	if (!backup)
		return (0);
	while (ft_strchr_index(backup, '\n') < 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (read_check(readed, &backup))
		{
			free(backup);
			backup = NULL;
			return (0);
		}
		buf[readed] = '\0';
		if (readed == 0 && (*backup))
			break ;
		backup = ft_add(backup, buf);
		if (!backup)
			return (0);
	}
	return (ft_cut(&backup));
}

// #include <stdio.h>

// int main(void)
// {	
// 	int		fd;
// 	char	*line;

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
