/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:22:00 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/21 22:35:52 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
	{
		if (n <= 9)
		{
			ft_putchar_fd (n + '0', fd);
		}
		else
		{
			ft_putnbr_fd (n / 10, fd);
			ft_putnbr_fd (n % 10, fd);
		}
	}
	else if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			write (fd, "-", 1);
			ft_putnbr_fd (n * -1, fd);
		}
	}
}
