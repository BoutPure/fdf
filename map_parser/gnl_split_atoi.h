/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_split_atoi.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:05:15 by vseel             #+#    #+#             */
/*   Updated: 2021/12/14 11:58:30 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_SPLIT_ATOI_H
# define GNL_SPLIT_ATOI_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../list_utils/list_utils.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
* Ft_split and utils to count words and free ** and * pointers.
*/
int		*ft_split_int(char const *s, char c);
int		*ft_split_free_int(int *res);
size_t	ft_wordcount(char const *s, char c);

/*
* GNL and utils to: 
* Find char in string;
* Join s2 to s1 via strjoin (frees s1);
* Create full copy or substring from s1 (can free s1 if 'y' passed);
*/
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strdup_free(const char *s1, char tofree);
char	*ft_substr_free(char const *s, unsigned int start, size_t len, char fr);

int		ft_strlen_s(const char *s, char c);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);

#endif /*GNL_SPLIT_ATOI_H*/
