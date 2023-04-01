/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:58:16 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/31 18:20:08 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	invalid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (-1);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (-1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

static void	base_convert(long long nbr, char *base, int base_len, int *i)
{
	if (nbr == 0)
		return ;
	else
	{
		base_convert(nbr / base_len, base, base_len, i);
		ft_putchar(base[nbr % base_len], i);
	}
}

void	ft_putnbr_base(int nbr, char *base, int *i)
{
	int			base_len;
	int			sign;
	long long	l_nbr;

	l_nbr = (long long)nbr;
	sign = 1;
	base_len = invalid(base);
	if (base_len == -1)
		return ;
	if (l_nbr < 0)
	{
		sign *= -1;
		l_nbr *= sign;
		ft_putchar('-', i);
	}
	if (l_nbr > 0)
		base_convert(l_nbr, base, base_len, i);
	else if (l_nbr == 0)
		ft_putchar(base[0], i);
}

static void	ft_unsigned_nbr(unsigned int nbr, char *base, int base_len, int *i)
{
	if (nbr == 0)
		return ;
	else
	{
		ft_unsigned_nbr(nbr / base_len, base, base_len, i);
		ft_putchar(base[nbr % base_len], i);
	}
}

void	ft_unsignednbr_base(unsigned int nbr, char *base, int *i)
{
	int	base_len;

	base_len = invalid(base);
	if (base_len == -1)
		return ;
	if (nbr > 0)
		ft_unsigned_nbr(nbr, base, base_len, i);
	else if (nbr == 0)
		ft_putchar(base[0], i);
}
