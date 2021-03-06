/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:56:17 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/31 15:54:49 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_echo_newline(char *cmd)
{
	int	i;

	if (ft_strncmp(cmd, "-n", 2))
		return (0);
	i = 2;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (0);
		i ++;
	}
	return (1);
}

int	builtin_echo(char **cmd)
{
	int	newline;
	int	i;
	// char temp[10];

	newline = 1;
	i = 1;
	while (cmd[i] && is_echo_newline(cmd[i]))
	{
		newline = 0;
		i ++;
	}
	while (cmd[i])
	{
		printf ("%s", cmd[i]);
		if (cmd[i + 1])
			printf (" ");
		i ++;
	}
	if (newline)
		printf ("\n");
	// printf("buffer: ");
	// read(0,temp,10);
	// write(1,temp,1);
	// printf("\n");
	return (EXIT_SUCCESS);
}
