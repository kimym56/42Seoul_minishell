/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:13:32 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/29 22:47:21 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
extern char **environ;

static int	ft_loop_cmds(t_vars *vars)
{
	g_glob.heredoc = 0;
	ft_lstclear(&vars->tokens);
	ft_cmd_lstclear(&vars->cmds);
	vars->cmdline = ft_free(vars->cmdline);
	vars->cmdline = readline(PROMPT);
	if (!vars->cmdline)
		return (0);
	if (vars->cmdline[0] && (!vars->last_cmdline || (vars->last_cmdline
				&& ft_strcmp(vars->cmdline, vars->last_cmdline))))
	{
		vars->last_cmdline = ft_free(vars->last_cmdline);
		vars->last_cmdline = ft_strdup(vars->cmdline);
		add_history(vars->cmdline);
	}
	if (!ft_tokenization(vars) || !ft_lstsize(vars->tokens))
		return (1);
	if (!ft_verify_syntax(vars))
	{
		ft_putendl_fd("minishell: syntax error.", STDERR_FILENO);
		return (1);
	}
	if (!ft_parse_cmds(vars))
		return (1);	// 220511
	execute_cmds(vars);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;
	struct termios term;
	
	(void)argc;
	(void)argv;
	if (!ft_init_vars(&vars, envp))
		return (EXIT_FAILURE);	//220510
	tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~(ECHOCTL);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
	vars.sa.sa_handler = signals_handler;
	vars.sa.sa_flags = 0;
	// signal(SIGINT,signals_handler);
	sigaction(SIGINT, &vars.sa, NULL);	// ctrl+c
	signal(SIGQUIT, SIG_IGN);	// ctrl+역슬래시 : 기본적으로 프로세스를 종료시킨 뒤 코어를 덤프
	vars.cmdline = ft_strdup("");
	while (ft_loop_cmds(&vars))
		;
	ft_free_program(&vars);
	ft_putendl_fd("exit", STDOUT_FILENO);
	return (g_glob.exit_status);
}
