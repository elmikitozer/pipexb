/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoidpt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:14:53 by myevou            #+#    #+#             */
/*   Updated: 2024/01/25 15:32:27 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// int	ft_putcharrt(char c)
// {
// 	write(2, &c, 1);
// 	return (1);
// }

int	ft_putvoidpt(unsigned long address, char format)
{
	int		len;

	len = 0;
	if (!address)
	{
		if (format == '0')
			return ((ft_putstrrt("(nil)")));
		else
			return (write (1, "0", 1));
	}
	else
	{
		len = count_void(address);
		if (format == '0')
			len += ft_putstrrt("0x");
		ft_printhexbase(address, format);
	}
	return (len);
}
