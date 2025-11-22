/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:15 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 16:24:41 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*casted_s;
	unsigned char	*casted_d;

	if (!src || !dest)
		return (dest);
	i = 0;
	casted_s = (unsigned char *)src;
	casted_d = (unsigned char *)dest;
	while (i < n)
	{
		casted_d[i] = casted_s[i];
		i++;
	}
	return (dest);
}
