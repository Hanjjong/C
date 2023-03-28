/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:44:11 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 15:16:17 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)malloc(sizeof(char) * (count * size));
	if (p == 0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		p[i++] = 0;
	}
	return ((void *)p);
}
