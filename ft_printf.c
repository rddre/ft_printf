/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:57:17 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/21 04:00:21 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_arg(va_list args, const char arg_print, int size)
{
	if (arg_print == 'c')
		size = ft_print(va_arg(args, int));
	else if (arg_print == 's')
		size = ft_print_str(va_arg(args, char *));
	else if (arg_print == 'p')
		size = 1;
	else if (arg_print == 'd' || arg_print == 'i')
		size = 1; //ft_print_nb(va_arg(args, char *), int len);
	else if (arg_print == 'u')
		size = 1;
	else if (arg_print == 'u')
		size = 1;
	else if (arg_print == 'x' || arg_print == 'X')
		size = 1;
	else
		size = ft_print(arg_print);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	size_print;

	i = 0;
	size_print = 0;
	va_list args;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size_print += ft_arg(args, str[i + 1], 0);
			i++;
		}
		else
			size_print += ft_print(str[i]);
		i++;
	}
	va_end(args);
	return (size_print);
}