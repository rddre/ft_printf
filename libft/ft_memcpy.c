/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:38:26 by asaracut          #+#    #+#             */
/*   Updated: 2024/10/17 03:24:50 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*udst;
	unsigned char	*usrc;

	if (!dst && !src)
		return (dst);
	udst = (unsigned char *) dst;
	usrc = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dst);
}
