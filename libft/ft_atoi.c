/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:38:47 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 15:07:05 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	size_t		i;
	const char	*spaces;

	i = 0;
	spaces = " \f\n\r\t\v";
	while (spaces[i])
	{
		if (spaces[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	to_int(const char *nptr)
{
	size_t	i;
	int		integer;

	i = 0;
	integer = 0;
	while (ft_isdigit(nptr[i]))
	{
		integer = (integer * 10) + (nptr[i] - '0');
		i++;
	}
	return (integer);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		integer;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	integer = to_int(&nptr[i]);
	return (sign * integer);
}
