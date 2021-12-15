/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:17:58 by vseel             #+#    #+#             */
/*   Updated: 2021/12/12 20:17:11 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (*(s1 + i))
		i++;
	ptr = (char *)malloc(i + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

static char	*ft_check(int n)
{
	char	*str;

	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	if (n == 0)
		str = ft_strdup("0");
	return (str);
}

static int	ft_numlen(int n)
{
	int		buf;
	int		len;

	buf = n;
	len = 0;
	while (buf != 0)
	{
		buf /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(float n, int multiplier)
{
	char	*str;
	int		len;
	int		buf;

	n *= (int)pow(10, multiplier);
	len = ft_numlen(n);
	buf = n;
	if (n == 0 || n == -2147483648)
		return (ft_check(n));
	if (n < 0)
		buf = -n;
	str = malloc(len + 1);
	if (!str)
		return (str);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = buf % 10 + 48;
		buf = buf / 10;
	}
	if (n < 0)
		str[++len] = '-';
	return (str);
}
