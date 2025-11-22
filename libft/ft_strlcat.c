/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:34 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 15:04:38 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	if (!src || !dst)
		return (0);
	i = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	if (dsize > destlen)
	{
		while (src[i] && destlen + i < dsize - 1)
		{
			dst[destlen + i] = src[i];
			i++;
		}
		dst[destlen + i] = '\0';
		return (srclen + destlen);
	}
	return (srclen + dsize);
}
