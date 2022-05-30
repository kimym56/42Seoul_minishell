/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:21:16 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 21:05:51 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < len)
	{
		if (i <= src_len)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i ++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		buffer_len;
	char	*buffer;

	if (!s)
		return (0);
	buffer_len = ft_strlen(s) - start;
	if (buffer_len > (int)len)
		buffer_len = len;
	if (buffer_len < 0)
		buffer_len = 0;
	buffer = (char *) malloc (buffer_len + 1);
	if (buffer == NULL)
		return (0);
	if (buffer_len > 0)
		ft_strncpy(buffer, s + start, buffer_len);
	buffer[buffer_len] = '\0';
	return (buffer);
}
