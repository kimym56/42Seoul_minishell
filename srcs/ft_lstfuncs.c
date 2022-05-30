/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeon <hyjeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:58:39 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/30 20:58:41 by hyjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_lstsize(t_list *lst)
{
	int	lstlen;

	lstlen = 0;
	while (lst)
	{
		lst = lst->next;
		lstlen ++;
	}
	return (lstlen);
}

t_list	*ft_lstnew(char *content, int type)
{
	t_list	*element;

	element = malloc (1 * sizeof(t_list));
	if (element == NULL)
		return (0);
	element->content = content;
	element->type = type;
	element->next = NULL;
	return (element);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && *lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*holder;

	if (!lst)
		return ;
	while (*lst)
	{
		holder = *lst;
		*lst = (*lst)->next;
		holder->content = ft_free(holder->content);
		holder = ft_free(holder);
	}
	*lst = NULL;
}
