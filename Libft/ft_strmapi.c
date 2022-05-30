/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:25:34 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 21:04:53 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buffer;
	unsigned int	i;

	if (!s)
		return (0);
	buffer = (char *) malloc (ft_strlen(s) + 1);
	if (buffer == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		buffer[i] = f(i, s[i]);
		i ++;
	}
	buffer[i] = '\0';
	return (buffer);
}
