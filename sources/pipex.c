/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:22:55 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/30 12:53:19 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *av[], char *envp[], int *fd)
{
	int		filein;

	filein = open_file(av[1], 2);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	dup2(filein, STDIN_FILENO);
	close(fd[READ_END]);
	close(filein);
	execute(av[2], envp);
}

void	parent_process(char *av[], char *envp[], int *fd)
{
	int		fileout;

	fileout = open_file(av[4], 1);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(fd[WRITE_END]);
	close(fileout);
	execute(av[3], envp);
}

int	main(int ac, char *av[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			operation_error(1);
		pid = fork();
		if (pid == -1)
			operation_error(2);
		if (pid == 0)
			child_process(av, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(av, envp, fd);
	}
	else
		input_error();
	return (0);
}
