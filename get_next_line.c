/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:53:17 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/04 15:50:33 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *buf, char *backup)
{
	int		count;
	char	*tmp;

	count = 1;
	while (count)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1) //오류 발생시 -1리턴 하므로 0리턴
			return (0);
		if (count == 0) // 0인 경우 더이상 읽은 것이 없으므로 read종료
			break ;
		buf[count] = '\0'; //위의 경우가 아니라면 버퍼의 마지막에 널삽입
		if (!backup)//백업이 없다면 빈문자 할당
			backup = ft_strdup("");
		tmp = backup;//static인 백업에 join해주기 위해 tmp를 만들어 join시켜줌
		backup = ft_strjoin(tmp, buf);
		if (!backup)
			return (0);
		if (ft_strchr(buf, '\n'))
			break ;//개행이 존재한다면 종료
	}
	return (backup);
}
// 지금 백업에는 개행문자나 널문자가 포함되어 있을 수도 있음 그걸 처리해야할 함수가 필요

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
//	backup = (라인의 가운데에 널이나 문자의 끝인지 확인하는 함수);
	return (line);
}

#include <stdio.h>

int main(void)
{	
	int fd;
	
	fd = 0;
	fd = open("./test",O_RDONLY);
	char * line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
