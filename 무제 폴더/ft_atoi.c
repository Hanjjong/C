/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:53:30 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/24 18:20:37 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					index;
	int					sign;
	unsigned long long	num;

	index = 0;
	sign = 1;
	num = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		num = num * 10 + (str[index] - '0');
		if (sign == 1 && num >= 9223372036854775807)
			return (-1);
		else if (sign == -1 && num > 9223372036854775807)
			return (0);
		index++;
	}
	return ((int)(sign * num));
}
