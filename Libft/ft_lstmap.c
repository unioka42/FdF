/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:53:31 by kokada            #+#    #+#             */
/*   Updated: 2023/05/25 12:48:50 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*next;

	if (f == NULL || del == NULL)
		return (NULL);
	head = NULL;
	next = ft_lstnew(f(lst->content));
	if (next == NULL)
		return (NULL);
	ft_lstadd_back(&head, next);
	tail = head;
	lst = lst->next;
	while (lst != NULL)
	{
		next = ft_lstnew(f(lst->content));
		if (next == NULL)
			ft_lstclear(&head, del);
		if (next == NULL)
			return (NULL);
		ft_lstadd_back(&tail, next);
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}
