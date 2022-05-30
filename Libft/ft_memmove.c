/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:43:44 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 20:55:28 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		source = src;
		dest = dst;
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		source = src + len - 1;
		dest = dst + len - 1;
		while (len--)
			*dest-- = *source--;
	}
	return (dst);
}
