/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:46:00 by achahlao          #+#    #+#             */
/*   Updated: 2024/07/13 13:48:08 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_count_wrd(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*ft_words(char const *str, int n)
{
	int		i;
	char	*niveau;

	i = 0;
	niveau = (char *)malloc(n + 1);
	if (niveau == NULL)
		return (NULL);
	while (i < n)
	{
		niveau[i] = str[i];
		i++;
	}
	niveau[i] = '\0';
	return (niveau);
}

static char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		taille;
	char	**strs;

	taille = ft_count_wrd(str, c);
	strs = (char **)malloc((sizeof(char *)) * (taille + 1));
	if (!strs)
		return (NULL);
	j = -1;
	while (++j < taille)
	{
		i = 0;
		while (*str == c && *str)
			str++;
		while (*(str + i) != c && *(str + i))
			i++;
		strs[j] = ft_words(str, i);
		if (!strs[j])
			return (ft_free(strs));
		while (*str != c && *str)
			str++;
	}
	strs[j] = 0;
	return (strs);
}
