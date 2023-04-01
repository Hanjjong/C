/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:23:19 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/31 18:54:26 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(unsigned char c, int *i)
{
	int	w_error;

	if (*i == -1)
		return ;
	else
		w_error = write(1, &c, 1);
	*i += 1;
	if (w_error < 0)
	{
		*i = -1;
		return ;
	}
}

void	ft_putstr(char *str, int *i)
{
	int	idx;
	int	w_error;

	w_error = 0;
	idx = 0;
	if (!str)
	{
		w_error = write(1, "(null)", 6);
		*i = *i + 6;
		if (w_error == -1)
		{
			*i = -1;
			return ;
		}
		return ;
	}
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx], i);
		idx++;
	}
}

static void	ft_memory_recul(unsigned long long n_addr, int *i)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n_addr == 0)
	{
		ft_putstr("0x", i);
		return ;
	}
	ft_memory_recul(n_addr / 16, i);
	ft_putchar(hex[n_addr % 16], i);
}

void	ft_memory(void *addr, int *i)
{
	unsigned long long	n_addr;

	n_addr = (unsigned long long)addr;
	if (n_addr == 0)
	{
		ft_putstr("0x0", i);
		return ;
	}
	ft_memory_recul(n_addr, i);
}
