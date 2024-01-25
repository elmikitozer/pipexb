/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:06 by myevou            #+#    #+#             */
/*   Updated: 2024/01/25 15:53:05 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	arg_type(va_list args, const char c, int *count)
{
	if (c == 'c')
		*count += ft_putcharrt(va_arg(args, int));
	else if (c == 's')
		*count += ft_putstrrt(va_arg(args, char *));
	else if (c == 'p')
		*count += ft_putvoidpt(va_arg(args, unsigned long long), '0');
	else if ((c == 'd') || (c == 'i'))
		*count += ft_itoa2(va_arg(args, int));
	else if (c == 'u')
		*count += ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x')
		*count += ft_putvoidpt(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		*count += ft_putvoidpt(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		*count += ft_putcharrt('%');
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str && str[i])
	{
		if (str[i] == '%')
			arg_type(args, str[++i], &count);
		else
			count += ft_putcharrt(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <unistd.h>
// #include<stdio.h>

// int	main(void)
// {
// 	printf("valeur de retour: %i\n", (ft_printf(" %s %s %s %s %s ", " - ", ""));
// 	printf("printf: %d\n", printf(" %s %s %s %s %s ", "", "4", "", "2 "));
// }
