/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:58:07 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 20:58:29 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	*ft_free_2d(char **array)
{
	int	i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

void	*ft_free_3d(char ***array)
{
	int	i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		ft_free_2d(array[i++]);
	return (NULL);
}
