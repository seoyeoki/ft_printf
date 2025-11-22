/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:26 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 15:00:13 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
			cnt++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (cnt);
}

void	free_all(char **strptr)
{
	int	i;

	i = 0;
	while (strptr[i])
	{
		free(strptr[i]);
		i++;
	}
	free(strptr);
}

void	fill_words(char **strptr, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	front;
	size_t	end;

	i = 0;
	front = 0;
	while (i < words)
	{
		while (s[front] && s[front] == c)
			front++;
		end = front;
		while (s[end] && s[end] != c)
			end++;
		strptr[i] = ft_substr(s, front, end - front);
		front = end;
		if (strptr[i] == NULL)
			free_all(strptr);
		i++;
	}
	strptr[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**strptr;
	size_t	words;

	words = count_words(s, c);
	strptr = (char **)malloc((words + 1) * sizeof(char *));
	if (!strptr)
		return (NULL);
	fill_words(strptr, s, c, words);
	return (strptr);
}
