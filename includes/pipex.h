/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:22:49 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/30 13:02:48 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define READ_END       0
# define WRITE_END      1
# define COLOR_RED      "\x1b[31m"
# define COLOR_BLUE_BG  "\x1B[44m"
# define COLOR_RESET    "\e[m"

void	input_error(void);
void	operation_error(int n);
int		open_file(char *av, int i);
char	*find_path(char *cmd, char *envp[]);
void	execute(char *av, char *envp[]);

#endif
