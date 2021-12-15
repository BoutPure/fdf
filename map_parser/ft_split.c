/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:17:58 by vseel             #+#    #+#             */
/*   Updated: 2021/12/14 11:55:14 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_split_atoi.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	len = ft_strlen_s(s, 0);
	if (c == 0)
		return (1);
	while (i < len)
	{
		if (s[i] != c && s[i] != '\n')
		{
			while (s[i] != c && i < len)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

int	*ft_split_free_int(int *res)
{
	free(res);
	return (NULL);
}

int	*ft_split_int(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;
	int		*res;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	res = (int *)malloc((sizeof(int) * (count + 1)));
	if (!res)
		return (0);
	while (s[i] != '\0' && j < count)
	{
		while (s[i] == c)
			i++;
		res[j] = ft_atoi(ft_substr_free(s, i, ft_strlen_s(&s[i], c), 'n'));
		i = i + ft_strlen_s(&s[i], c);
		j++;
	}
	return (res);
}
