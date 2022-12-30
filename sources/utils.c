/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:22:58 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/30 13:04:36 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	input_error(void)
{
	ft_putstr_fd(COLOR_RED "Error: Invalid Input/s\n", 2);
	ft_putstr_fd(COLOR_RESET "Try: \x1B[44m./pipex file1 cmd1 cmd2 file2\n", 1);
	exit(EXIT_SUCCESS);
}

void	operation_error(int n)
{
	if (n == 0)
		perror(COLOR_RED "Error opening file");
	else if (n == 1)
		perror(COLOR_RED "Error in pipe");
	else if (n == 2)
		perror(COLOR_RED "Error in fork");
	else if (n == 3)
		perror(COLOR_RED "Error executing commands");
	exit(EXIT_FAILURE);
}

int	open_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	else if (i == 2)
		file = open(av, O_RDONLY | O_CLOEXEC, 0777);
	if (file == -1)
		operation_error(0);
	return (file);
}

char	*find_path(char *cmd, char *envp[])
{
	char	*part_path;
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	execute(char *av, char *envp[])
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		operation_error(3);
}
