/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:59:51 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/19 21:27:23 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
