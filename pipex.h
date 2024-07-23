/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:48:51 by achahlao          #+#    #+#             */
/*   Updated: 2024/07/13 18:16:53 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	print_error(void);
void	ft_process_child1(char **av, char **evn, int *fd);
void	ft_process_child2(char **av, char **env, int *fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char const *str, char c);
void	free_split(char **split);
char	*get_path(char *cmd, char **env);
void	ft_putstr_fd(char *str, int fd);
int		ft_strchar(char *s, char c);

#endif