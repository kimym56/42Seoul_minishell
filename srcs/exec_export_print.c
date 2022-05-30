/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeon <hyjeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:57:32 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/30 20:57:34 by hyjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_env_var(char *var)
{
	int	i;

	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	i = 0;
	while (var[i] && var[i] != '=')
		ft_putchar_fd(var[i++], STDOUT_FILENO);
	if (i > 0)
	{
		if (var[i] == '=')
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(&var[i + 1], STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
		}
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	print_export(char **envp)
{
	size_t	cmp;
	size_t	arr_len;
	size_t	i;
	size_t	j;

	arr_len = ft_arrlen(envp);
	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (!envp[j])
			j ++;
		cmp = j;
		while (j < arr_len)
		{
			if (envp[j] && envp[cmp]
				&& ft_strcmp(envp[j], envp[cmp]) < 0)
				cmp = j;
			j ++;
		}
		print_env_var(envp[cmp]);
		envp[cmp] = ft_free(envp[cmp]);
		i ++;
	}
}
