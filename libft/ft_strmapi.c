/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:28:15 by myevou            #+#    #+#             */
/*   Updated: 2023/10/24 17:35:16 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	fr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!fr)
		return (NULL);
	while (s[i])
	{
		fr[i] = (*f)(i, s[i]);
		i++;
	}
	fr[i] = 0;
	return (fr);
}
