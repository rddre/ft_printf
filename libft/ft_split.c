/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:02:37 by asaracut          #+#    #+#             */
/*   Updated: 2024/10/30 00:00:02 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strdup_split(const char *str, int start, int end)
{
	char	*le_mot;
	int		i;

	i = 0;
	le_mot = malloc((end - start + 1) * sizeof(char));
	if (!le_mot)
		return (NULL);
	while (start < end)
	{
		le_mot[i] = str[start];
		i++;
		start++;
	}
	le_mot[i] = 0;
	return (le_mot);
}

static void	*ft_free(char **tableau, int nb, int i)
{
	while (i < nb)
		free(tableau[i++]);
	free(tableau);
	return (NULL);
}

static void	ft_gagner_3ligne(size_t *i, int *compteur_mots, int *le_mot)
{
	*i = 0;
	*compteur_mots = 0;
	*le_mot = -1;
}

static int	mots_nb(const char *str, char c)
{
	int	nb_de_mots;
	int	meme_mot;

	nb_de_mots = 0;
	meme_mot = 0;
	while (*str)
	{
		if (*str != c && meme_mot == 0)
		{
			meme_mot = 1;
			nb_de_mots++;
		}
		else if (*str == c)
			meme_mot = 0;
		str++;
	}
	return (nb_de_mots);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	int		compteur_mots;
	int		le_mot;

	ft_gagner_3ligne(&i, &compteur_mots, &le_mot);
	res = ft_calloc((mots_nb(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && le_mot < 0)
			le_mot = i;
		else if ((s[i] == c || i == ft_strlen(s)) && le_mot >= 0)
		{
			res[compteur_mots] = strdup_split(s, le_mot, i);
			if (!(res[compteur_mots]))
				return (ft_free(res, compteur_mots, 0));
			le_mot = -1;
			compteur_mots++;
		}
		i++;
	}
	return (res);
}
