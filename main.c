/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:55:37 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/21 03:57:12 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main(int ac, char **test)
{
	ft_printf(" %w 123456789 %c 123456789 %% 1 %s 2 %p\n", 'A', "str", 'D');
	   printf(" %w 123456789 %c 123456789 %% 1 %s 2 %p\n", 'A', "str", 'D');
	
	printf("\n\n\n  %d    %d    ", ft_printf(" %w 123456789 %c 123456789 %% 1 %s 2 %p\n", 'A', "str", 'D'), printf(" %w 123456789 %c 123456789 %% 1 %s 2 %p\n", 'A', "str", 'D'));
	return (0);
}