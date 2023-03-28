/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:18:44 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 15:19:36 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	detec_len(long long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	int			len;
	char		*arr;

	nbr = (long long)n;
	len = detec_len(nbr);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		arr[0] = '-';
	}
	if (nbr == 0)
		arr[0] = '0';
	arr[len] = '\0';
	while (nbr != 0)
	{
		arr[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (arr);
}
