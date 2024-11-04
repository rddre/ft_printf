/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:57:17 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/04 18:52:53 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	verifi_element(char c)
{
	c = 5;
	return (0);
}

int	ft_printf(const char *main, ...)
{
	size_t		i;
	char	phrase_finale[50];

	i = 0;
	va_list args;
	while (i < ft_strlen(main))
	{
		if (verifi_element(main[i]) > 0)
			return (0);
		else
			phrase_finale[i] = main[i];
		i++;
	}
	ft_putstr_fd(phrase_finale, 1);
	va_end (args);
	return (1);
}
/*
int	main(int ac, char **test)
{
	ft_printf(test[1]);
	return (0);
}*/