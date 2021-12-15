/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:47:49 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 20:09:25 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_split_atoi.h"

int	atoi_minus_check(char c, int *minus)
{
	int	i;

	i = 0;
	if (c == '-')
	{
		*minus *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	n;

	i = 0;
	minus = 1;
	n = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
	{
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	i += atoi_minus_check(str[i], &minus);
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - 48);
	free ((char *)str);
	return (n * minus);
}
