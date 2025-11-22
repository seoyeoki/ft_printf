/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

char	*apply_width(char *str, t_parse_set *set)
{
	char	*result;
	int		len;
	int		width;

	if (!str || set->width <= 0)
		return (str);
	len = ft_strlen(str);
	width = set->width;
	if (len >= width)
		return (str);
	result = (char *)malloc(width + 1);
	if (!result)
	{
		free(str);
		return (NULL);
	}
	if (set->flag & MINUS)
		do_left_pad(result, str, width, get_padding_char(set));
	else
		do_right_pad(result, str, width, get_padding_char(set));
	result[width] = '\0';
	free(str);
	return (result);
}

char	*apply_precision(char *str, t_parse_set *set)
{
	char	*result;
	int		len;
	int		precision;

	if (!str || set->precision < 0)
		return (str);
	len = ft_strlen(str);
	precision = set->precision;
	if (len >= precision)
		return (str);
	result = (char *)malloc(precision + 1);
	if (!result)
	{
		free(str);
		return (NULL);
	}
	ft_memset(result, '0', precision - len);
	ft_memcpy(result + precision - len, str, len);
	result[precision] = '\0';
	free(str);
	return (result);
}

char	*apply_flags(char *str, t_parse_set *set)
{
	char	*result;

	result = str;
	if (set->flag & PLUS && str[0] != '-')
	{
		result = ft_strjoin("+", str);
		free(str);
	}
	else if (set->flag & SPACE && str[0] != '-')
	{
		result = ft_strjoin(" ", str);
		free(str);
	}
	return (result);
}

char	*ft_itoa_base(long long n, int base, int uppercase)
{
	char	*result;
	int		len;
	int		neg;

	if (base < 2 || base > 16)
		return (NULL);
	neg = (n < 0);
	len = calc_itoa_base_len(n, base, neg);
	result = (char *)malloc(len + neg + 1);
	if (!result)
		return (NULL);
	if (neg)
		result[0] = '-';
	result[len + neg] = '\0';
	fill_itoa_base_digits(result, n, base, len + neg);
	if (uppercase)
	{
		while (len--)
			if (result[len + neg] >= 'a' && result[len + neg] <= 'f')
				result[len + neg] = result[len + neg] - 'a' + 'A';
	}
	return (result);
}

char	*ft_utoa_base(unsigned long long n, int base, int uppercase)
{
	char	*result;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	len = calc_utoa_base_len(n, base);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	fill_utoa_digits(result, n, base, len);
	if (uppercase)
	{
		while (len--)
			if (result[len] >= 'a' && result[len] <= 'f')
				result[len] = result[len] - 'a' + 'A';
	}
	return (result);
}
