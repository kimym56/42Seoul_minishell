/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeon <hyjeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:58:04 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/30 20:58:06 by hyjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_pwd(void)
{
	char	cwd[4096];

	getcwd(cwd, 4096);
	ft_putendl_fd(cwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
