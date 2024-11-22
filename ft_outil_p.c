/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:59:21 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/22 13:30:52 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_put_ptr(uintptr_t num)
{
	int	secu;

	secu = 0;
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			secu = ft_print(num + '0');
		else
			secu = ft_print(num - 10 + 'a');
	}
	return (secu);
}

int	ft_print_p(unsigned long long ptr, int size, int secu)
{
	secu = write(1, "0x", 2);
	size += secu;
	if (secu < 0)
		return (-1);
	if (ptr == 0)
		size += write(1, "0", 1);
	else
	{
		secu = ft_put_ptr(ptr);
		size += ft_ptr_len(ptr);
	}
	if (secu < 0)
		return (-1);
	return (size);
}
