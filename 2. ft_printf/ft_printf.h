/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:23:56 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/30 21:43:37 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(unsigned char c, int *i);
void	ft_putstr(char *str, int *i);
void	ft_memory(void *addr, int *i);
void	ft_putnbr_base(int nbr, char *base, int *i);
void	ft_unsignednbr_base(unsigned int nbr, char *base, int *i);

#endif