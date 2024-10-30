/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:37:43 by asaracut          #+#    #+#             */
/*   Updated: 2024/10/17 06:34:12 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		symbole;
	size_t	result;

	result = 0;
	symbole = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			symbole *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && result < LONG_MAX)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > LONG_MAX && symbole == 1)
		return (-1);
	else if (result > LONG_MAX)
		return (0);
	return (result * symbole);
}
