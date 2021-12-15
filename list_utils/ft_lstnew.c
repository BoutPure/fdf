/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:47:49 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 21:02:47 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_parse	*ft_lstnew(void *z_val_arr)
{
	t_parse	*node;

	node = (t_parse *)malloc(sizeof(t_parse));
	if (node == NULL)
		return (NULL);
	node->z_val_arr = z_val_arr;
	node->next = NULL;
	return (node);
}
