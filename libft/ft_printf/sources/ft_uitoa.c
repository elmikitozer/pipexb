/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:11:11 by myevou            #+#    #+#             */
/*   Updated: 2024/01/25 01:31:48 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	get_nb_digit(long n_l)
{
	unsigned int	nb_digit;

	if (n_l == 0)
		return (1);
	nb_digit = 0;
	while (n_l > 0)
	{
		n_l /= 10;
		nb_digit++;
	}
	return (nb_digit);
}

static void	convert_nb(char *outstr, long n_l, unsigned int nb_digit)
{
	outstr[nb_digit] = '\0';
	outstr[--nb_digit] = n_l % 10 + '0';
	n_l /= 10;
	while (n_l > 0)
	{
		outstr[--nb_digit] = n_l % 10 + '0';
		n_l /= 10;
	}
}

int	ft_uitoa(unsigned int n)
{
	char			*outstr;
	long			n_l;
	unsigned int	nb_digit;
	int				len;

	n_l = n;
	nb_digit = get_nb_digit(n_l);
	outstr = malloc(sizeof(char) * (nb_digit + 1));
	if (!outstr)
		return (0);
	convert_nb(outstr, n_l, nb_digit);
	len = ft_putstrrt(outstr);
	free(outstr);
	return (len);
}
