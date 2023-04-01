/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:13:39 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/31 18:53:03 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format(va_list ap, char c, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), i);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), i);
	else if (c == 'p')
		ft_memory(va_arg(ap, void *), i);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(ap, int), "0123456789", i);
	else if (c == 'u')
		ft_unsignednbr_base(va_arg(ap, unsigned int), "0123456789", i);
	else if (c == 'x')
		ft_unsignednbr_base(va_arg(ap, unsigned int), "0123456789abcdef", i);
	else if (c == 'X')
		ft_unsignednbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", i);
	else if (c == '%')
		ft_putchar(c, i);
	else
		*i = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_format(ap, *(format), &i);
		}
		else
			ft_putchar(*(format), &i);
		if (i == -1)
		{
			va_end(ap);
			return (i);
		}
		format++;
	}
	va_end(ap);
	return (i);
}
