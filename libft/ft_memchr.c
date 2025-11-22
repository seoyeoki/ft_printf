/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:11 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 13:53:05 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*casted_s;

	casted_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (casted_s[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
