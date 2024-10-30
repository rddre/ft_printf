/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:38:36 by asaracut          #+#    #+#             */
/*   Updated: 2024/10/17 05:54:13 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	cc = (char) c;
	i = 0;
	if (s[i] == cc)
		return ((char *) &s[i]);
	while (s[i])
	{
		i++;
		if (s[i] == cc)
			return ((char *) &s[i]);
	}
	return (0);
}
