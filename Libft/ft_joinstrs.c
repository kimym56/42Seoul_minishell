/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:23:19 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 20:59:54 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinstrs(char **array, char c)
{
	char	*str;
	size_t	i;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	i = 0;
	while (array[i])
	{
		str = ft_stradd(str, array[i]);
		if (!str)
			return (ft_free(str), NULL);
		if (array[i + 1])
		{
			str = ft_stradd(str, &c);
			if (!str)
				return (ft_free(str), NULL);
		}
		i ++;
	}
	return (str);
}
