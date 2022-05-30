/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:43:44 by yongmiki          #+#    #+#             */
/*   Updated: 2022/05/30 20:55:28 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *) malloc (ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (0);
	ft_strcpy(s2, s1);
	return (s2);
}
