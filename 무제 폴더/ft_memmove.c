/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:44:59 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 16:23:27 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (i < num)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (num--)
			((unsigned char *)dst)[num] = ((unsigned char *)src)[num];
	}
	return (dst);
}
