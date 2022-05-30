/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeon <hyjeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:56:03 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/30 20:56:05 by hyjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_next_cmd(t_cmd *cmd)
{
	int	subsh_lvl;
	int	i;

	subsh_lvl = 0;
	i = 0;
	if (!cmd->subsh_lvl[0])
		return (1);
	while (1)
	{
		i ++;
		subsh_lvl += cmd->subsh_lvl[0];
		if (cmd->subsh_lvl[1])
			subsh_lvl -= cmd->subsh_lvl[1];
		if (subsh_lvl <= 0)
			break ;
		cmd = cmd->next;
	}
	return (i);
}

static int	handle_operators(t_cmd **cmd)
{
	int	i;

	if (((*cmd)->type == AND && g_glob.exit_status != 0)
		|| ((*cmd)->type == OR && g_glob.exit_status == 0))
	{
		i = ft_next_cmd((*cmd));
		while (i--)
			(*cmd) = (*cmd)->next;
		return (1);
	}
	return (0);
}

static void	child_wait(t_vars *vars)
{
	int		status;

	waitpid(g_glob.pid, &status, 0);
	if (WIFEXITED(status))
		g_glob.exit_status = WEXITSTATUS(status);
	if (WTERMSIG(status) == SIGQUIT || WTERMSIG(status) == SIGINT)
	{
		g_glob.exit_status = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit: 3", STDOUT_FILENO);
		if (WTERMSIG(status) == SIGINT)
			ft_putstr_fd("^C\n", STDOUT_FILENO);
	}
	signal(SIGQUIT, signal_child_sub);
	signal(SIGINT, signal_child_sub);
	while (waitpid(-1, NULL, 0) != -1)
		;
	sigaction(SIGINT, &vars->sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

static pid_t	execute_cmd(t_cmd **cmd, t_vars *vars)
{
	pid_t	pid;
	int		is_fork;

	pid = 0;
	while (*cmd)
	{
		is_fork = exec_is_fork(*cmd);
		if (is_fork)
		{
			signal(SIGINT, SIG_IGN);
			pid = fork();
		}
		if (pid == -1)
			return (perror("minishell: fork"), -1);
		if (pid == 0)
			exec_cmd_child(*cmd, vars, is_fork);
		if (pid == 0 && is_fork)
			exit(EXIT_FAILURE);
		ft_close_pipes(*cmd);
		if (!(*cmd)->next || ((*cmd)->next && (*cmd)->next->type != PIPE))
			break ;
		(*cmd) = (*cmd)->next;
	}
	return (pid);
}

void	execute_cmds(t_vars *vars)
{
	t_cmd	*cmd;

	ft_init_pipes(&vars->cmds);
	if (!exec_init_heredoc(&vars->cmds, vars->envp))
		return ;
	exec_init_pipes(&vars->cmds);
	cmd = vars->cmds;
	while (cmd)
	{
		if (handle_operators(&cmd))
			continue ;
		g_glob.pid = execute_cmd(&cmd, vars);
		if (g_glob.pid == -1)
			break ;
		else if (g_glob.pid > 0)
			child_wait(vars);
		cmd = cmd->next;
	}
	g_glob.pid = 0;
}
