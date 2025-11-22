/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_padding_helpers.c                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

char	get_padding_char(t_parse_set *set)
{
	if (set->flag & ZERO && !(set->flag & MINUS) && set->precision < 0)
		return ('0');
	return (' ');
}

void	do_left_pad(char *res, char *str, int w, char pad)
{
	int	len;

	len = ft_strlen(str);
	ft_memcpy(res, str, (size_t)len);
	ft_memset(res + len, pad, (size_t)(w - len));
}

void	do_right_pad(char *res, char *str, int w, char pad)
{
	int	len;

	len = ft_strlen(str);
	if (pad == '0' && (str[0] == '-' || str[0] == '+' || str[0] == ' '))
	{
		res[0] = str[0];
		ft_memset(res + 1, pad, (size_t)(w - len));
		ft_memcpy(res + w - len + 1, str + 1, (size_t)(len - 1));
	}
	else
	{
		ft_memset(res, pad, (size_t)(w - len));
		ft_memcpy(res + w - len, str, (size_t)len);
	}
}
