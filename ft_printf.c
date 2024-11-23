/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:57:17 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/23 02:22:20 by asaracut         ###   ########.fr       */
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

int	ft_purcent(const char *str, int *i, va_list args, int *size_print)
{
	int	secu;

	secu = ft_arg(args, str[*i + 1], 0);
	if (secu < 0)
		return (-1);
	*size_print += secu;
	(*i)++;
	return (0);
}

int	ft_char(char c, int *size_print)
{
	int	secu;

	secu = ft_print(c);
	if (secu < 0)
		return (-1);
	*size_print += secu;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size_print;
	va_list	args;

	i = 0;
	size_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (ft_purcent(str, &i, args, &size_print) < 0)
				return (-1);
		}
		else
		{
			if (ft_char(str[i], &size_print) < 0)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (size_print);
}
