/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:30:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/10 00:51:48 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	ft_varname_len_export(char *var_name)
{
	int	i;

	i = 0;
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
			break ;
		i ++;
	}
	return (i);
}

static int	ft_is_varname_export(char *var_name)
{
	int	invalid;
	int	i;

	invalid = 0;
	i = 0;
	while (var_name[i] && var_name[i] != '='
		&& (var_name[i] != '+' || var_name[i + 1] != '=')) // <- 이 줄 조건문 삭제?
	{
		if (i == 0 && !ft_isalpha(var_name[i]) && var_name[i] != '_')
			invalid = 1;
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
			invalid = 1;
		i ++;
	}
	if (invalid)
	{
		ft_putstr_fd("minishell: export: '", STDERR_FILENO);
		ft_putstr_fd(var_name, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		return (0);
	}
	return (1);
}

static int	ft_change_env_var(char ***envp, char *var)
{
	int	i;

	i = 0;
	while ((*envp)[i])
	{
		if (!ft_strncmp((*envp)[i], var, ft_varname_len_export(var)))
		{
			if (var[ft_varname_len_export(var)] == '+'	// + 처리 해줘야함?
				&& var[ft_varname_len_export(var) + 1] == '=')
				(*envp)[i] = ft_stradd((*envp)[i], &ft_strchr(var, '=')[1]);
			else if (ft_strlen((*envp)[i]) == ft_varname_len_export(var)) // envp[i]에서 '=' 이 없는 경우가 있나? 
				(*envp)[i] = ft_stradd((*envp)[i], ft_strchr(var, '='));
			else
			{
				(*envp)[i] = ft_free((*envp)[i]);
				(*envp)[i] = ft_strdup(var);
			}
			if (!(*envp)[i])
				return (0);
		}
		i ++;
	}
	return (1);
}

static int	edit_env(char ***envp, char *argv)
{
	char	*var_name;
	char	*var_value;

	var_name = ft_substr(argv, 0, ft_varname_len_export(argv));
	if (!var_name)
		return (0);
	var_value = ft_getenv(var_name, *envp);
	if ((var_value || ft_arr_has_str(*envp, var_name)) && !ft_strchr(argv, '='))	// var_value가 존재(0이상)하면서 '=' 이 없을때
		return (ft_free(var_name), 1);	// 이거 왜 1? 0아님? 위에 ft_strchr이 0면 error 아닌가
	if (!var_value && !ft_arr_has_str(*envp, var_name))	// var_value가 error로 인한 null 일때
	{
		*envp = ft_add_str2arr(*envp, argv);
		if (!*envp)
			return (ft_free(var_name), 0);
	}
	else
	{
		if (!ft_change_env_var(envp, argv))
			return (ft_free(var_name), 0);
	}
	return (ft_free(var_name), 1);
}

int	builtin_export(char **cmd, char ***envp)
{
	char	**temp_envp;
	int		i;
	// cmd(shlvl[1])이 공백이면 에러처리 => 필요? 삭제?
	if (!cmd[1])
	{
		temp_envp = ft_arrdup(*envp);
		if (!temp_envp)
			return (EXIT_FAILURE);
		print_export(temp_envp);
		temp_envp = ft_free(temp_envp);
		return (EXIT_SUCCESS);
	}
	//
	i = 1;
	while (cmd[i])
	{
		if (ft_is_varname_export(cmd[i]))
		{
			if (!edit_env(envp, cmd[i]))
				return (EXIT_FAILURE);
		}
		i ++;
	}
	return (EXIT_SUCCESS);
}
