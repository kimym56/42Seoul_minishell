/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:35:11 by ybensell          #+#    #+#             */
/*   Updated: 2022/05/18 23:45:35 by yongmiki         ###   ########.fr       */
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
		if (subsh_lvl <= 0)	// 음수 되는 경우가 있나..?
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
		// printf("cmd before : %s\n",*(*cmd)->cmd);
		i = ft_next_cmd((*cmd));//220516
		// printf("cmd after : %s\n",*(*cmd)->cmd);
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
			ft_putstr_fd("\n", STDOUT_FILENO);
	}
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
			printf("pid : %d\n",pid);
		}
		if (pid == -1)
			return (perror("minishell: fork"), -1);
		if (pid == 0)
			exec_cmd_child(*cmd, vars, is_fork);	// fork된 후에 자식 프로세스가 실행 
		if (pid == 0 && is_fork)	// fork된 자식 프로세스 종료 (pid 초기값 0인 fork안된 프로세스가 종료되는것 방지)
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
	t_list *token;
	ft_init_pipes(&vars->cmds);
	if (!exec_init_heredoc(&vars->cmds, vars->envp))
		return ;
	exec_init_pipes(&vars->cmds);//220513
	cmd = vars->cmds;
	token = vars->tokens;
	while (token){
		// printf(" token : %s\n",token->content);
		token = token->next;
	}
	while (cmd)
	{
		// printf("cmd : %s, type: %d, pipe: %d %d,\n",*cmd->cmd, cmd->type, cmd->pipe[0],cmd->pipe[1]);
	// printf("heredoc: %d %d\n",cmd->heredoc[0],cmd->heredoc[1]);
	// printf("sub_lvl : %d %d\n",cmd->subsh_lvl[0], cmd->subsh_lvl[1]);
	// printf("red: %s, red_type: %d\n",cmd->redirect->content,cmd->redirect->type);
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
