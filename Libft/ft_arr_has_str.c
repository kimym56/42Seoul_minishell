/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_has_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:50:33 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 20:53:54 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arr_has_str(char **arr, char *str)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], str) == 0)
			return (1);
		i ++;
	}
	return (0);
}
