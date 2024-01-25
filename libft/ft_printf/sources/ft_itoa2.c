/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:11:11 by myevou            #+#    #+#             */
/*   Updated: 2024/01/25 01:32:33 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// static int	ft_len(int nbr)
// {
// 	int	len;

// 	len = 0;
// 	if (nbr <= 0)
// 		len = 1;
// 	while (nbr != 0)
// 	{
// 		nbr = nbr / 10;
// 		len++;
// 	}
// 	return (len);
// }

// static void	process(char *alpha, int len, unsigned int *nbr)
// {
// 	while (len >= 0)
// 	{
// 		alpha[len] = *nbr % 10 + '0';
// 		*nbr = *nbr / 10;
// 		len = len - 1;
// 	}
// }

// char	*ft_itoa(int n)
// {
// 	unsigned int	nbr;
// 	int				sign;
// 	int				len;
// 	char			*alpha;

// 	sign = 1;
// 	if (n < 0)
// 	{
// 		sign = -1;
// 		nbr = -n;
// 	}
// 	else
// 		nbr = n;
// 	len = ft_len(n) - 1;
// 	alpha = malloc(sizeof(char) * len + 2);
// 	if (!alpha)
// 		return (NULL);
// 	process(alpha, len, &nbr);
// 	if (sign == -1)
// 		alpha[0] = '-';
// 	return (alpha);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s \n", ft_itoa(321154));
// }

static unsigned int	get_nb_digit(long n_l, int sign)
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
	if (sign == -1)
		nb_digit++;
	return (nb_digit);
}

static void	convert_nb(char *outstr, long n_l, unsigned int nb_digit,
		int sign)
{
	outstr[nb_digit] = '\0';
	outstr[--nb_digit] = n_l % 10 + '0';
	n_l /= 10;
	while (n_l > 0)
	{
		outstr[--nb_digit] = n_l % 10 + '0';
		n_l /= 10;
	}
	if (sign == -1)
		outstr[0] = '-';
}

int	ft_itoa2(int n)
{
	char			*outstr;
	long			n_l;
	unsigned int	nb_digit;
	int				sign;
	int				len;

	sign = 1;
	if (n < 0)
	{
		n_l = (long)n * -1;
		sign = -1;
	}
	else
		n_l = n;
	nb_digit = get_nb_digit(n_l, sign);
	outstr = malloc(sizeof(char) * (nb_digit + 1));
	if (!outstr)
		return (0);
	convert_nb(outstr, n_l, nb_digit, sign);
	len = ft_putstrrt(outstr);
	free(outstr);
	return (len);
}
