/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:54:57 by heolivei          #+#    #+#             */
/*   Updated: 2022/11/30 09:55:26 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lstcpy;

	lstcpy = lst;
	if (!lst)
		return (0);
	while (lstcpy->next != NULL)
			lstcpy = lstcpy->next;
	return (lstcpy);
}
