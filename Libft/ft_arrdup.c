/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:43:44 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 20:55:28 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **array)
{
	char	**new_array;
	int		i;

	new_array = ft_calloc(ft_arrlen(array) + 1, sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			new_array = ft_free_2d(new_array);
			return (NULL);
		}
		i ++;
	}
	return (new_array);
}
