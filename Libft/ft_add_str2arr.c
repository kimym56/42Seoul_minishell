/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str2arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:50:13 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 20:54:07 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_str2arr(char **array, char *str)
{
	char	**new_array;
	size_t	array_len;
	size_t	i;

	array_len = 0;
	if (array)
		array_len = ft_arrlen(array);
	new_array = (char **) ft_calloc(array_len + 2, sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < array_len)
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
			return (ft_free_2d(new_array), NULL);
		i ++;
	}
	new_array[i] = ft_strdup(str);
	if (!new_array[i])
		return (ft_free_2d(new_array), NULL);
	array = ft_free_2d(array);
	return (new_array);
}
