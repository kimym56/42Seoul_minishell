/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:46:03 by ybensell          #+#    #+#             */
/*   Updated: 2022/05/28 21:18:11 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_built_in(char *name)
{
	if (!name)
		return (0);
	if (ft_strcmp(name, "echo") == 0
		|| ft_strcmp(name, "pwd") == 0
		|| ft_strcmp(name, "cd") == 0
		|| ft_strcmp(name, "env") == 0
		|| ft_strcmp(name, "export") == 0
		|| ft_strcmp(name, "unset") == 0
		|| ft_strcmp(name, "exit") == 0)
		return (1);
	return (0);
}

int	exec_built_in(char **cmd, t_vars *vars)
{
	int	status;

	status = 0;
	if (ft_strcmp(cmd[0], "echo") == 0)
		status = builtin_echo(cmd);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		status = builtin_pwd();
	else if (ft_strcmp(cmd[0], "cd") == 0)
		status = builtin_cd(cmd, &vars->envp);	// 0528
	else if (ft_strcmp(cmd[0], "env") == 0)
		status = builtin_env(vars->envp);
	else if (ft_strcmp(cmd[0], "export") == 0)
		status = builtin_export(cmd, &vars->envp);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		status = builtin_unset(cmd, &vars->envp);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		status = builtin_exit(cmd);
	return (status);
}
