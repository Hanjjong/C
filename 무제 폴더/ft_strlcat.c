/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:58:07 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 17:16:01 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len >= dstsize)
		return (src_len + dstsize);
	while (src[i] != '\0' && ((dest_len + i + 1) < dstsize))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (src_len + dest_len);
}
