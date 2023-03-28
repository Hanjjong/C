/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:22:44 by jonhan            #+#    #+#             */
/*   Updated: 2023/03/23 16:51:52 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*result;
	void	*new;

	result = 0;
	while (lst)
	{
		new = f(lst->content);
		tmp = ft_lstnew(new);
		if (!tmp)
		{
			ft_lstclear(&result, del);
			del(new);
			return (0);
		}
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
