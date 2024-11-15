/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:57:17 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/15 04:59:24 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print(char c)
{
	write(1, &c, 1);
	return (1);
}
// ------------------------------------------------------- fichier outil
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_print_str(char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}


//---------------------------------------------------- fin fichier outil
int	ft_arg(va_list args, const char arg_print, int size)
{
	if (arg_print == 'c')
		size = ft_print(va_arg(args, int));
	else if (arg_print == 's')
		size = ft_print_str(va_arg(args, char *));
	else if (arg_print == 'p')
		size = 1;
	else if (arg_print == 'd' || arg_print == 'i')
		size = 1;
	else if (arg_print == 'u')
		size = 1;
	else if (arg_print == 'u')
		size = 1;
	else if (arg_print == 'x' || arg_print == 'X')
		size = 1;
	else if (arg_print == '%')
		size = ft_print('%');
	else
		size = -1;
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

#include <stdio.h>
int	main(int ac, char **test)
{
	ft_printf("123456789 %c 123456789 %% 1 %s 2 %p\n", 'A', "str", 'D');
	   printf("123456789 %c 123456789 %% 1 %s 2 %p\n", 'A', "str", 'D');
	
	printf("  %d    %d    ", printf("\n \n 123456789 %c 123456789 %% 1 %s 2 \n", 'A', "str", 'D'), ft_printf("123456789 %c 123456789 %% 1 %s 2 \n", 'A', "str", 'D'));
	return (0);
}

/*-------------------------------- erreur a gerer
#include <stdio.h>
int	main(int ac, char **test)
{
	ft_printf("123456789 %c 123456789 %% 1 %s 2 %q q q \n", 'A', "str", 'D');
	   printf("123456789 %c 123456789 %% 1 %s 2 %q q q \n", 'A', "str", 'D');
	
	printf("  %d    %d    ", printf("\n \n 123456789 %c 123456789 %% 1 %s 2 \n", 'A', "str", 'D'), ft_printf("123456789 %c 123456789 %% 1 %s 2 \n", 'A', "str", 'D'));
	return (0);
}*/