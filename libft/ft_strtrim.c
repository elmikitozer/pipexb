/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:28:53 by myevou            #+#    #+#             */
/*   Updated: 2023/11/10 20:51:39 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ischar(char c, const char *set)
// {
// 	size_t	i;

// 	i = 0;
// 	while (set[i])
// 	{
// 		if (set[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static char	*trim_end(const char *s1, const char *set, size_t *j, size_t i)
// {
// 	size_t	len;
// 	char	*dst;

// 	len = ft_strlen(s1);
// 	j = 0;
// 	while (ischar(s1[len - *j - 1], set))
// 		j++;
// 	// dst = ft_calloc(sizeof(char), len + 1 - (*j + i) + 1);
// 	dst = ft_calloc(sizeof(char), 1000);
// 	if (!dst)
// 		return (NULL);
// 	while (*j < len - (*j + i))
// 	{
// 		*(dst + *j) = *(s1 + i + *j);
// 		*j += 1;
// 	}
// 	return (dst);
// }

// char	*ft_strtrim(const char *s1, char const *set)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	len;
// 	char	*dest;

// 	if (!s1)
// 		return (NULL);
// 	i = 0;
// 	len = ft_strlen(s1);
// 	while (ischar(s1[i], set))
// 		i++;
// 	j = 0;
// 	if (i == len)
// 		dest = malloc(1);
// 	else
// 		dest = trim_end(s1, set, &j, i);
// 	if (dest)
// 		(dest[j]) = 0;
// 	return (dest);
// }

static char	*find_begin(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		in_set;

	in_set = 0;
	i = 0;
	j = 0;
	while (s1[i])
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i++;
	}
	return ((char *) s1 + i);
}

static char	*find_end(char const *s1, char const *set, char const *begin)
{
	size_t	i;
	size_t	j;
	int		in_set;

	in_set = 0;
	i = ft_strlen(s1) - 1;
	j = 0;
	while (s1 + i >= begin)
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i--;
	}
	if (s1 + i < begin)
		return ((char *) begin);
	return ((char *) s1 + i);
}

static char	*fill_str(char const *begin, char const *end)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (end - begin + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (begin + i <= end)
	{
		new[i] = begin[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	char	*end;
	char	*new;

	if (!set || !s1)
		return (NULL);
	begin = find_begin(s1, set);
	end = find_end(s1, set, s1);
	if ((!s1[0] || end < begin))
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
	}
	else
		new = fill_str(begin, end);
	if (!new)
		return (NULL);
	return (new);
}
