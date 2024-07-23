/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:48:34 by achahlao          #+#    #+#             */
/*   Updated: 2024/07/13 17:48:16 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

char	*valid_path(char *path_value, char *cmd)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		j;

	paths = ft_split(path_value, ':');
	if (paths == NULL)
		return (NULL);
	j = 0 ;
	while (paths[j])
	{
		tmp = ft_strjoin(paths[j], "/");
		if (!tmp)
			(write(2, "Error\n", 6), exit(1));
		path = ft_strjoin(tmp, cmd);
		if (!path)
			(write(2, "Error\n", 6), exit(1));
		free(tmp);
		if (access(path, F_OK) == 0)
			return (free_split(paths), path);
		free(path);
		j++;
	}
	free_split(paths);
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;

	i = 0 ;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (valid_path(env[i] + 5, cmd));
		i++;
	}
	if (ft_strchar (cmd, '/'))
		ft_putstr_fd ("pipex: no such file or directory:", 2);
	else
		ft_putstr_fd ("pipex : command not found: ", 2);
	(ft_putstr_fd(cmd, 2), ft_putstr_fd("\n", 2));
	exit(EXIT_FAILURE);
	return (NULL);
}
