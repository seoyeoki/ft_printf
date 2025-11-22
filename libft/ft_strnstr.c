/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:14:23 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 23:55:42 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	found(const char *middle, const char *little, size_t left_len)
{
	size_t	i;

	i = 0;
	while (middle[i] && little[i] && i < left_len)
	{
		if (middle[i] != little[i])
			return (0);
		i++;
	}
	if (little[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!big || !little)
		return (0);
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (found(big + i, little, len - i))
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
