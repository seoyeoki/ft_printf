/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_itoa_helpers.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

int	calc_itoa_base_len(long long n, int base, int neg)
{
	unsigned long long	temp;
	int					len;

	if (neg)
		temp = -(unsigned long long)n;
	else
		temp = (unsigned long long)n;
	len = 1;
	temp = temp / base;
	while (temp > 0)
	{
		len++;
		temp = temp / base;
	}
	return (len);
}

void	fill_itoa_base_digits(char *result, long long n, int base, int pos)
{
	unsigned long long	temp;
	const char			*digits;

	digits = "0123456789abcdef";
	if (n < 0)
		temp = -(unsigned long long)n;
	else
		temp = (unsigned long long)n;
	while (temp > 0)
	{
		pos--;
		result[pos] = digits[temp % base];
		temp = temp / base;
	}
}

int	calc_utoa_base_len(unsigned long long n, int base)
{
	unsigned long long	temp;
	int					len;

	temp = n;
	len = 1;
	temp = temp / base;
	while (temp > 0)
	{
		len++;
		temp = temp / base;
	}
	return (len);
}

void	fill_utoa_digits(char *res, unsigned long long n, int base, int len)
{
	const char			*digits;
	unsigned long long	temp;

	digits = "0123456789abcdef";
	temp = n;
	while (len--)
	{
		res[len] = digits[temp % base];
		temp = temp / base;
	}
}
