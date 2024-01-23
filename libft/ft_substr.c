/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:44:43 by myevou            #+#    #+#             */
/*   Updated: 2023/11/10 20:41:45 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*sub;
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i])
// 		i++;
// 	sub = malloc((sizeof(char) * (i - start + 1)) + 1);
// 	if (!sub)
// 		return (NULL);
// 	if (i < start + len)
// 	{
// 		i = 0;
// 		while (i < len)
// 		{
// 			sub[i] = s[start + i];
// 			i++;
// 		}
// 		sub[i] = 0;
// 		return (sub);
// 	}
// 	return (NULL);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	if (!s)
// 		return (NULL);
// 	if (ft_strlen(s) < start)
// 	{
// 		dst = malloc(sizeof(char))
// 			return (NULL);
// 		dst[0] = '\0';
// 		return (dst);
// 	}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
