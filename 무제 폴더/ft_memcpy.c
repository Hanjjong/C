/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:31:30 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 16:25:49 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dst;
	unsigned char	*c_src;

	i = 0;
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (!c_dst && !c_src)
		return (NULL);
	if (c_dst == c_src)
		return (c_dst);
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
