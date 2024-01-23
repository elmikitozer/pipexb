/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:42:55 by myevou            #+#    #+#             */
/*   Updated: 2023/11/10 21:00:21 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	if ((!dst || !src) && !size)
		return (0);
	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}

// size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
// {
// 	size_t	dst_len;
// 	size_t	index;
// 	size_t	i;

// 	dst_len = ft_strlen(d);
// 	index = 0;
// 	while (d[index])
// 		index++;
// 	i = 0;
// 	while (s[i] && (i + index + 1) < (dstsize))
// 	{
// 		d[index + i] = (unsigned char)s[i];
// 		i++;
// 	}
// 	if (i < dstsize)
// 		d[index + i] = '\0';
// 	if (dstsize <= dst_len)
// 		return (ft_strlen(s) + dstsize);
// 	else
// 		return (ft_strlen(s) + dst_len);
// }
