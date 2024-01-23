/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:36:02 by myevou            #+#    #+#             */
/*   Updated: 2023/11/10 21:03:36 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
// {
// 	size_t	i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	while (src[count])
// 	{
// 		count++;
// 	}
// 	if (size)
// 	{
// 		while (src[i] && (i < size - 1))
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 	}
// 	dest[i] = 0;
// 	return (count);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		dst[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}
