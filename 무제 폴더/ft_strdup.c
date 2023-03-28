/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:57:53 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 18:40:44 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (des == NULL)
		return (NULL);
	while (src[j] != '\0')
	{
		des[j] = src[j];
		j++;
	}
	des[j] = '\0';
	return (des);
}
