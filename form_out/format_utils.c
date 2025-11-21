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
	char	padding_char;

	if (!str || set->width <= 0)
		return (str);
	
	len = ft_strlen(str);
	width = set->width;
	
	if (len >= width)
		return (str);
	
	padding_char = ' ';
	if (set->flag & ZERO && !(set->flag & MINUS))
		padding_char = '0';

	result = (char *)malloc(width + 1);
	if (!result)
		return (str);

	if (set->flag & MINUS)
	{
		ft_memcpy(result, str, len);
		ft_memset(result + len, padding_char, width - len);
	}
	else
	{
		ft_memset(result, padding_char, width - len);
		ft_memcpy(result + width - len, str, len);
	}
	
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
		return (str);
	
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
	char	*digits;
	int		len;
	int		neg;
	long long	temp;

	if (base < 2 || base > 16)
		return (NULL);
	
	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	neg = (n < 0);
	temp = neg ? -n : n;
	len = 1;
	
	while (temp /= base)
		len++;
	
	result = (char *)malloc(len + neg + 1);
	if (!result)
		return (NULL);
	
	if (neg)
		result[0] = '-';
	
	result[len + neg] = '\0';
	temp = neg ? -n : n;
	
	while (len--)
	{
		result[len + neg] = digits[temp % base];
		temp /= base;
	}
	
	return (result);
}

char	*ft_utoa_base(unsigned long long n, int base, int uppercase)
{
	char	*result;
	char	*digits;
	int		len;
	unsigned long long	temp;

	if (base < 2 || base > 16)
		return (NULL);
	
	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	temp = n;
	len = 1;
	
	while (temp /= base)
		len++;
	
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	
	result[len] = '\0';
	temp = n;
	
	while (len--)
	{
		result[len] = digits[temp % base];
		temp /= base;
	}
	
	return (result);
}
