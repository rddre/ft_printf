/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:16:11 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/22 06:54:58 by asaracut         ###   ########.fr       */
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
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_print_nb(int n, int len)
{
	char	print[12];
	int		index;

	index = 0;
	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n == 0)
		return (ft_print('0'));
	if (n < 0)
	{
		ft_print('-');
		n = -n;
		len++;
	}
	while (n != 0)
	{
		print[index++] = (n % 10) + '0';
		n /= 10;
	}
	while (--index >= 0)
		len += ft_print(print[index]);
	return (len);
}

int	ft_print_unsigned_nb(unsigned int n, int len)
{
	char	print[12];
	int		index = 0;

	if (n == 0)
		return (ft_print('0'));

	while (n != 0)
	{
		print[index++] = (n % 10) + '0';
		n /= 10;
	}
	while (--index >= 0)
		len += ft_print(print[index]);

	return (len);
}

int	ft_puthexa(unsigned int nbr, char format)
{
	int	i;
 
	i = 0;
	if (nbr >= 16)
	{
		i += ft_puthexa((nbr / 16), format);
		i += ft_puthexa((nbr % 16), format);
	}
	else
	{
		if (nbr <= 9)
			i += ft_putchar(nbr + '0');
		else if (format == 'x')
			i += ft_putchar(nbr - 10 + 'a');
		else if (format == 'X')
			i += ft_putchar(nbr - 10 + 'A');
	}
	return (i);
}