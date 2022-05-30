/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:48:41 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 21:04:03 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] && i + dst_len < dstsize - 1)
		{
			dst[i + dst_len] = src[i];
			i ++;
		}
		if (i > 0)
			dst[i + dst_len] = '\0';
	}
	if (dstsize >= dst_len)
		return (dst_len + src_len);
	else
		return (src_len + dstsize);
}
