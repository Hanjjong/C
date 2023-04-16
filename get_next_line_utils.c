/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:54:49 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/16 17:17:34 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
	{
		return (0);
	}
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str != (char)c)
		return (NULL);
	return ((char *)str);
}

char	*ft_strdup(char *src)
{
	int		index;
	int		j;
	char	*des;

	j = 0;
	index = 0;
	if (!src)
	{
		return (NULL);
	}
	while (src[index] != '\0')
		index++;
	des = (char *)malloc((index + 1) * sizeof(char));
	if (!des)
		return (NULL);
	while (src[j] != '\0')
	{
		des[j] = src[j];
		j++;
	}
	des[j] = '\0';
	return (des);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (s1 && s2)
	{
		tmp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!tmp)
			return (0);
		while (*s1)
			tmp[i++] = *(s1++);
		while (*s2)
			tmp[i++] = *(s2++);
		tmp[i] = '\0';
	}
	else
		return (0);
	return (tmp);
}

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	temp;
	size_t	i;

	i = 0;
	temp = ft_strlen(src);
	if (src[0] == '\0')
	{
		dst[0] = '\0';
		return (0);
	}
	if (dstsize == 0)
		return (temp);
	while (i < temp && i + 1 < dstsize)
	{
		if (src[i] == '\0')
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (temp);
}
