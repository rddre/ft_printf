/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:16:11 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/21 05:51:20 by asaracut         ###   ########.fr       */
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
