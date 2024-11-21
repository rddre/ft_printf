/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:16:14 by asaracut          #+#    #+#             */
/*   Updated: 2024/11/21 04:31:16 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *main, ...);
size_t	ft_strlen(const char *str);
int 	ft_print_str(char *str);
int		ft_print(char c);
int		ft_print_nb(int n, int len);

#endif