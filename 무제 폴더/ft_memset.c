/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:21:19 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 16:58:33 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	set;
	size_t			i;

	set = (unsigned char)c;
	p = (unsigned char *)b;
	i = 0;
	while (i < len)
		p[i++] = set;
	return (b);
}
