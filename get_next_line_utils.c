/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:54:49 by jonhan            #+#    #+#             */
/*   Updated: 2023/04/06 17:19:09 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strdup(const char *src)
{
	int		index;
	int		j;
	char	*des;

	j = 0;
	index = 0;
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
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
