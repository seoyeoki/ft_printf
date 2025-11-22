/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:47 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 14:34:34 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	min(size_t size1, size_t size2)
{
	if (size1 < size2)
		return (size1);
	else
		return (size2);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	to_fill;
	char	*sub;

	i = 0;
	s_len = ft_strlen(s);
	if (s_len > start)
	{
		to_fill = min(len, s_len - start);
		sub = (char *)malloc((to_fill + 1) * sizeof(char));
		if (!sub)
			return (NULL);
		while (i < to_fill)
		{
			sub[i] = s[i + start];
			i++;
		}
	}
	else
		sub = (char *)malloc(1 * sizeof(char));
	sub[i] = '\0';
	return (sub);
}
