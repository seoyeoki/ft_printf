/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:17 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 13:37:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move_forward(unsigned char *dest, unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	move_backward(unsigned char *dest, unsigned char *src, size_t n)
{
	while (n > 0)
	{
		--n;
		dest[n] = src[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*casted_s;
	unsigned char	*casted_d;

	if (!src || !dest)
		return (NULL);
	casted_s = (unsigned char *)src;
	casted_d = (unsigned char *)dest;
	if (src < dest && dest < src + n)
		move_backward(casted_d, casted_s, n);
	else
		move_forward(casted_d, casted_s, n);
	return (dest);
}
