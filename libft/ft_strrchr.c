/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:39:08 by asaracut          #+#    #+#             */
/*   Updated: 2024/10/19 02:05:05 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cc;
	char	*res;

	res = NULL;
	cc = (char) c;
	i = 0;
	if (s[i] == cc)
		res = (char *) &s[i];
	while (s[i])
	{
		i++;
		if (s[i] == cc)
			res = (char *) &s[i];
	}
	return (res);
}
