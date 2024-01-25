/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:52:23 by myevou            #+#    #+#             */
/*   Updated: 2024/01/25 00:10:45 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			while (s[++i] != '\'')
				words++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_tab(char *new, char const *s, int count)
{
	size_t	i;

	i = 0;
	while (s[i] && i < (size_t)(count))
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

int	coucount(size_t *index, const char *s, char c)
{
	int	count;

	count = 0;
	if (s[(*index) + count] == '\'')
	{
		(*index)++;
		while (s[(*index) + count] && s[(*index) + count] != '\'')
			count++;
	}
	else
	{
		while (s[(*index) + count] && s[(*index) + count] != c)
			count++;
	}
	return (count);
}

static void	set_mem(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (s[index])
	{
		count = coucount(&index, s, c);
		if (count > 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return ;
			fill_tab(tab[i], (s + index), count);
			i++;
			index = index + count;
		}
		else
			index++;
	}
	tab[i] = 0;
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	set_mem(tab, s, c);
	return (tab);
}

// int	main(void)
// {
// 	int	k;

// 	k = 0;
// 	while (k < 9)
// 	{
// 		printf("split[%d] = %s\n", k,
			// ft_split("awk '{count++} END {print count}'", ' ')[k]);
			// 		k++;
			// 	}
			// 	return (0);
			// }
