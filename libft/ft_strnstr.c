/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:09:58 by myevou            #+#    #+#             */
/*   Updated: 2023/11/10 21:01:09 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	is_found(const char *str, const char *to_find)
// {
// 	int	i;

// 	i = 0;
// 	while (to_find[i])
// 	{
// 		if (to_find[i] != str[i])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// char	*ft_strnstr(const char *s1, const char *s2, size_t len)
// {
// 	if (!s2[0])
// 		return (s1);
// 	while (*s1 && len)
// 	{
// 		if (s1[0] == s2[0] && is_found(s1, s2) != 0)
// 			return (s1);
// 		s1++;
// 		len--;
// 	}
// 	return (0);
// }

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	len_n;
	size_t	i;
	size_t	j;

	if ((!s1 || !s2) && !len)
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char *) s1);
	len_n = ft_strlen(s2);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s1[i + j] == s2[j] && i + j < len)
			j++;
		if (j == len_n)
			return ((char *) s1 + i);
		i++;
	}
	return (NULL);
}
