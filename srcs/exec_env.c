/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeon <hyjeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:56:38 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/30 20:56:41 by hyjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strchr(envp[i], '='))
			ft_putendl_fd(envp[i], STDOUT_FILENO);
		i ++;
	}
	return (EXIT_SUCCESS);
}
