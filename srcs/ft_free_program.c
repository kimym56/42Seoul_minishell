/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeon <hyjeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:01:00 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/30 21:01:01 by hyjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_program(t_vars *vars)
{
	vars->cmdline = ft_free(vars->cmdline);
	vars->last_cmdline = ft_free(vars->last_cmdline);
	vars->envp = ft_free_2d(vars->envp);
	ft_lstclear(&vars->tokens);
	ft_cmd_lstclear(&vars->cmds);
}
