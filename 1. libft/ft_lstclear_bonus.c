/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:05:43 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/23 16:08:23 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		del((void *)tmp1->content);
		free(tmp1);
		tmp1 = tmp2;
	}
	*lst = NULL;
}
