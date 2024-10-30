/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:38:30 by asaracut          #+#    #+#             */
/*   Updated: 2024/10/17 02:42:23 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t	len)
{
	size_t			i;
	unsigned char	*udst;
	unsigned char	*usrc;

	if (!dst && !src)
		return (dst);
	i = 0;
	udst = (unsigned char *) dst;
	usrc = (unsigned char *) src;
	if (udst > usrc)
		while (len-- > 0)
			udst[len] = usrc[len];
	else
	{
		while (i < len)
		{
			udst[i] = usrc[i];
			i++;
		}
	}
	return (dst);
}
