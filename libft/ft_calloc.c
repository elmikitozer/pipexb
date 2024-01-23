/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:24:01 by myevou            #+#    #+#             */
/*   Updated: 2023/11/10 19:33:11 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t	i;
// 	size_t	total;
// 	char	*mem;

// 	total = size * count;
// 	mem = malloc(total);
// 	if (!mem)
// 		return (NULL);
// 	i = 0;
// 	while (i < total)
// 		mem[i++] = 0;
// 	return ((void *)mem);
// }

static void	*ft_memalloc(size_t size)
{
	void	*new;
	size_t	i;

	new = (void *) malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(unsigned char *)(new + i) = 0;
		i++;
	}
	return (new);
}

void	*ft_calloc(size_t count, size_t size)
{
	if (size != 0 && count > ((size_t) - 1 / size))
		return (NULL);
	return (ft_memalloc(count * size));
}
