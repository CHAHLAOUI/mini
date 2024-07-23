/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:16:54 by achahlao          #+#    #+#             */
/*   Updated: 2024/07/13 16:56:31 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_wait(int a, int b)
{
	if (close(a) == -1 || close(b) == -1)
		print_error();
	if (wait(NULL) < 0 || wait(NULL) < 0)
		print_error();
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	int		i;
	pid_t	id;

	i = -1;
	if (ac == 5)
	{
		if (pipe(p_fd) == -1)
			print_error();
		while (++i < 2)
		{
			id = fork();
			if (id < 0)
				print_error();
			if (id == 0 && i == 0)
				ft_process_child1 (av, env, p_fd);
			else if (id == 0 && i == 1)
				ft_process_child2(av, env, p_fd);
		}
		close_wait(p_fd[0], p_fd[1]);
	}
	else
		ft_putstr_fd("comme : ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	return (0);
}
