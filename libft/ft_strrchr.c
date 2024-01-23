/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:01:32 by myevou            #+#    #+#             */
/*   Updated: 2023/11/10 21:03:22 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strrchr(const char *s, int c)
// {
// 	int		i;
// 	char	*ptr;

// 	i = 0;
// 	ptr = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			ptr = (char *)(s + i);
// 		i++;
// 	}
// 	if (s[i] == c)
// 		ptr = (char *)(s + i);
// 	return (ptr);
// }

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char) c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
