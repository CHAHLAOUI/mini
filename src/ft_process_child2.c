/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_child2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:05:50 by achahlao          #+#    #+#             */
/*   Updated: 2024/07/13 17:08:32 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_process_child2(char **av, char **env, int *p_fd)
{
	int		outfile_fd;
	char	**cmd2;

	outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
	{
		perror("error open outfile");
		exit(EXIT_FAILURE);
	}
	if (close(p_fd[1]) == -1 || dup2(p_fd[0], STDIN_FILENO) < 0 || \
		close(p_fd[0]) == -1 || dup2(outfile_fd, STDOUT_FILENO) < 0 \
		|| close(outfile_fd) == -1)
		print_error();
	cmd2 = ft_split(av[3], ' ');
	if (!cmd2[0])
		return (ft_putstr_fd ("pipex: command not found\n", 2), exit(1));
	if (execve(get_path(cmd2[0], env), cmd2, NULL) == -1)
	{
		perror("error executing cmd2");
		exit(EXIT_FAILURE);
	}
}
