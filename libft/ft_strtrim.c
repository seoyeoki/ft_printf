/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:45 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 15:09:57 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(int c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*empty_str(void)
{
	char	*empty;

	empty = (char *)malloc(1 * sizeof(char));
	empty[0] = '\0';
	return (empty);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	front;
	size_t	end;

	front = 0;
	end = ft_strlen(s1);
	while (isset(s1[front], set))
		front++;
	while (isset(s1[end - 1], set))
		end--;
	if (front < end)
		trimmed = ft_substr(s1, front, end - front);
	else
		trimmed = empty_str();
	return (trimmed);
}
