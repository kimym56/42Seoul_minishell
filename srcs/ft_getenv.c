/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeon <hyjeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:01:19 by hyjeon            #+#    #+#             */
/*   Updated: 2022/05/30 21:01:21 by hyjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(char *var, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], var, ft_strlen(var))
			&& envp[i][ft_strlen(var)] == '=')
			return (&envp[i][ft_strlen(var) + 1]);
		i ++;
	}
	return (NULL);
}
