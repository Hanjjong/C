/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:53:17 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/16 17:29:04 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_read_line(int fd, char *buf, char *backup)
{
	int		count;
	char	*temp_pointer;

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
		if (!backup)
			return (NULL);
		temp_pointer = backup;
		backup = ft_strjoin(backup, buf);
		free(temp_pointer);
		temp_pointer = NULL;
		if (!backup)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_extract(char *line, char *backup)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		// free(backup);
		// backup = 0;
		return (0);
	}
	result = ft_strdup(line + i + 1);
	if (!result)
	{	
		free(backup);
		backup = 0;
		return (NULL);
	}
	if (result[0] == '\0')
	{
		free(result);
		// free(backup);
		// backup = 0;
		result = NULL;
		return (NULL);
	}
	return (result);
}

static char	*ft_cut(char *line)
{
	char	*result;

	if (ft_strchr(line, '\n'))
	{
		result = (char *)malloc((ft_strchr(line, '\n') - line + 2));
		if (!result)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy(result, line, ft_strchr(line, '\n') - line + 2);
		free(line);
		return (result);
	}
	else if (ft_strchr(line, '\0'))
	{
		if (line[0] == '\0')
		{
			free(line);
			return (0);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = ft_extract(line, backup);
	line = ft_cut(line);
	return (line);
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
// 	// line = get_next_line(fd);
// 	// printf("|%s|", line);
// 	// line = get_next_line(fd);
// 	// printf("|%s|", line);
// 	// line = get_next_line(fd);
// 	// printf("|%s|", line);
// 	// line = get_next_line(fd);
// 	// printf("|%s|", line);
// 	// line = get_next_line(fd);
// 	// printf("|%s|", line);
// 	// line = get_next_line(fd);
// 	// printf("|%s|", line);
// 	return (0);
// }
