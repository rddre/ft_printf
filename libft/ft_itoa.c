/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:03:36 by asaracut          #+#    #+#             */
/*   Updated: 2024/10/25 23:22:02 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nbr(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return ((int) i);
}

static void	ft_write_nbr(char *res, long n)
{
	if (n == 0)
		return ;
	res[ft_len_nbr(n) - 1] = '0' + (n % 10);
	ft_write_nbr(res++, n / 10);
}

static void	negatif_itoa(char *res, int n)
{
	res[0] = '-';
	ft_write_nbr(&res[1], -1 * (long) n);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	int		sign;

	sign = 1;
	i = ft_len_nbr((long) n);
	if (n == 0)
	{
		res = ft_calloc(2, sizeof(char));
		if (!res)
			return (NULL);
		return (res[0] = '0', res);
	}
	if (n < 0)
		sign = -1;
	if (n < 0)
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (sign < 0)
		negatif_itoa(res, n);
	else
		ft_write_nbr(res, (long) n);
	return (res);
}
/*
#include <stdio.h>
#include <limits.h>

int	main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-10));
	printf("%s\n", ft_itoa(-9874));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	return 0;
}*/