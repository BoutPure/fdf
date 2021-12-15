/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:22:05 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 21:27:10 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H
# include "../map_parser/gnl_split_atoi.h"

typedef struct s_parse
{
	int				*z_val_arr;
	int				num_count;
	struct s_parse	*next;
}	t_parse;
/*
* map_parser get the filename, open and proceed in line by line 
* also creating a list, where each elem. contain a ptr to int array
* of values for futher map creating, number of elems in array
* and ptr to next list elem.
* If error occurs while Open, Read, Close a file or in mem. alloc:
* errno will be updated, error message will be written 
* and program will shutdown by exit();
*/
t_parse	*ft_map_parser(char *filename);
t_parse	*ft_lstnew(void *z_val_arr);
int		ft_lstsize(t_parse *lst);
void	ft_lstadd_back(t_parse **lst, t_parse *new);
void	ft_error_exit(char *errmessage, int errnum);

#endif /*LIST_UTILS_H*/