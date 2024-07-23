/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:48:38 by achahlao          #+#    #+#             */
/*   Updated: 2024/07/12 15:47:31 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*niveau;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	niveau = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!niveau)
		return (NULL);
	while (s1[i] != '\0')
	{
		niveau[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		niveau[i] = s2[j];
		i++;
		j++;
	}
	niveau[i] = '\0';
	return (niveau);
}
