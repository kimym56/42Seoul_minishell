/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:43:44 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 20:55:28 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*buffer;
	size_t		i;

	buffer = s;
	i = 0;
	while (i < n)
	{
		if ((i > 0 && !(unsigned char)buffer[i])
			|| (unsigned char)buffer[i] == (unsigned char)c)
			return ((void *)&buffer[i]);
		i ++;
	}
	return (0);
}
