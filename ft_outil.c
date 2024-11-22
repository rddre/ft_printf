/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:16:11 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/22 14:03:19 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_nb(int n, int len, int index)
{
	char	print[12];

	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n == 0)
		return (ft_print('0'));
	if (n < 0)
	{
		if (ft_print('-') == -1)
			return (-1);
		n = -n;
		len++;
	}
	while (n != 0)
	{
		print[index++] = (n % 10) + '0';
		n /= 10;
	}
	while (--index >= 0)
	{
		if (ft_print(print[index]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_print_unsigned_nb(unsigned int n, int len)
{
	char	print[12];
	int		index;

	index = 0;
	if (n == 0)
		return (ft_print('0'));
	while (n != 0)
	{
		print[index++] = (n % 10) + '0';
		n /= 10;
	}
	while (--index >= 0)
	{
		if (ft_print(print[index]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_puthexa(unsigned int nbr, char format, int i, int secu)
{
	if (nbr >= 16)
	{
		secu = ft_puthexa((nbr / 16), format, 0, 0);
		if (secu == -1)
			return (-1);
		i += secu;
		secu = ft_puthexa((nbr % 16), format, 0, 0);
		if (secu == -1)
			return (-1);
		i += secu;
	}
	else
	{
		if (nbr <= 9)
			secu = ft_print(nbr + '0');
		else if (format == 'x')
			secu = ft_print(nbr - 10 + 'a');
		else if (format == 'X')
			secu = ft_print(nbr - 10 + 'A');
		if (secu == -1)
			return (-1);
		i += secu;
	}
	return (i);
}
