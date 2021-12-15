/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:27:38 by vseel             #+#    #+#             */
/*   Updated: 2021/12/14 11:59:35 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_split_atoi.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen_s(str, 0));
}

void	ft_error_exit(char *errmessage, int errnum)
{
	ft_putstr(errmessage);
	exit(errnum);
}

void	map_parser_main_loop(t_parse *temp, t_parse *parsedata,
	char *map_next_line, int fd)
{
	while (map_next_line)
	{
		if (temp != parsedata)
			temp = ft_lstnew(NULL);
		temp->num_count = ft_wordcount(map_next_line, ' ');
		if (temp->num_count != parsedata->num_count)
			ft_error_exit("Error, different amount \
of numbers in this and prev. line\n", 14);
		temp->z_val_arr = ft_split_int(map_next_line, ' ');
		free (map_next_line);
		if (!temp->z_val_arr)
			ft_error_exit("Error when trying to split \
the line file\n", 12);
		if (temp != parsedata)
			ft_lstadd_back(&parsedata, temp);
		else
			temp = NULL;
		map_next_line = get_next_line(fd);
	}
}

t_parse	*ft_map_parser(char *filename)
{
	int		fd;
	char	*map_next_line;
	t_parse	*parsedata;
	t_parse	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Error when trying to open file\n", 10);
	map_next_line = get_next_line(fd);
	if (!map_next_line)
		ft_error_exit("Error when trying to get map next line\n", 11);
	parsedata = ft_lstnew(NULL);
	temp = parsedata;
	map_parser_main_loop(temp, parsedata, map_next_line, fd);
	if (close(fd) < 0)
		ft_error_exit("Error when trying to close file\n", 13);
	return (parsedata);
}
