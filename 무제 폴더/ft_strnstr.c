/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:57:12 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 17:50:47 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (needle[j] != '\0' && i + j < len
				&& haystack[i + j] == needle[j])
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
