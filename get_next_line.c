/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:53:17 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/05 20:55:25 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*ft_read(int fd, char *buf, char *backup)
{
	int		count;
	char	*tmp;

	count = 1;
	while (count)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
			return (0);
		else if (count == 0)
			break ;
		buf[count] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free(tmp);
		if (!backup)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_detecnl(char *line)
{	
	char	*result ;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - 1);
	if (!result)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = ft_detecnl(line);
	return (line);
}
/*

#include <stdio.h>

int main(void)
{	
	int fd;
	char * line;

	fd = 0;
	fd = open("./test",O_RDONLY);
	line = get_next_line(fd);
	printf("|%s|\n", line);
	line = get_next_line(fd);
	printf("|%s|\n", line);
	line = get_next_line(fd);
	printf("|%s|\n", line);
	line = get_next_line(fd);
	printf("|%s|\n", line);
	line = get_next_line(fd);
	printf("|%s|\n", line);
	line = get_next_line(fd);
	printf("|%s|\n", line);
	return (0);
}
*/