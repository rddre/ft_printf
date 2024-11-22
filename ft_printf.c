/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:57:17 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/22 14:02:41 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print(char c)
{
	return (write(1, &c, 1));
}

int	ft_arg(va_list args, const char arg_print, int size)
{
	if (arg_print == 'c')
		size = ft_print(va_arg(args, int));
	else if (arg_print == 's')
		size = ft_print_str(va_arg(args, char *));
	else if (arg_print == 'p')
		size = ft_print_p(va_arg(args, unsigned long long), 0, 0);
	else if (arg_print == 'd' || arg_print == 'i')
		size = ft_print_nb(va_arg(args, int), 0, 0);
	else if (arg_print == 'u')
		size = ft_print_unsigned_nb(va_arg(args, unsigned int), 0);
	else if (arg_print == 'x' || arg_print == 'X')
		size = ft_puthexa(va_arg(args, unsigned int), arg_print, 0, 0);
	else
		size = ft_print(arg_print);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size_print;
	int		secu;
	va_list	args;

	secu = 0;
	i = 0;
	size_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			secu = ft_arg(args, str[i + 1], 0);
			if (secu < 0)
				return (-1);
			size_print += secu;
			i++;
		}
		else
		{
			secu = ft_print(str[i]);
			if (secu < 0)
				return (-1);
			size_print += secu;
		}
		i++;
	}
	va_end(args);
	return (size_print);
}
