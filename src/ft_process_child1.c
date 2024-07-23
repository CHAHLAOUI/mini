/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_child1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:46:24 by achahlao          #+#    #+#             */
/*   Updated: 2024/07/13 17:05:40 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_process_child1(char **av, char **env, int *p_fd)
{
	int		infile_fd;
	char	**cmd1;

	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd < 0)
		(perror("error open infile"), exit(EXIT_FAILURE));
	if (close (p_fd[0] == -1) || dup2 (infile_fd, STDIN_FILENO) < 0 \
		|| close (infile_fd) == -1 || \
		dup2(p_fd[1], STDOUT_FILENO) < 0 || close(p_fd[1]) == -1)
		print_error();
	cmd1 = ft_split(av[2], ' ');
	if (!cmd1[0])
		return (ft_putstr_fd("pipex:command not found\n", 2), exit(1));
	if (execve(get_path(cmd1[0], env), cmd1, NULL) == -1)
		(perror("error executing cmd1"), exit(EXIT_FAILURE));
}
