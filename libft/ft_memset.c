/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:18 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 12:01:21 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*casted_s;

	casted_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		casted_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
