/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:23 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 15:10:45 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_arr(char *arr)
{
	size_t	i;
	size_t	size;
	char	temp;

	i = 0;
	size = ft_strlen(arr);
	while (i < size / 2)
	{
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
		i++;
	}
}

static void	put_num(char *arr, long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		arr[i++] = '0';
	while (n > 0)
	{
		arr[i] = n % 10 + '0';
		i++;
		n /= 10;
	}
	reverse_arr(arr);
	arr[i] = '\0';
}

static void	ft_static_itoa(char *arr, int n)
{
	int		minus;
	long	num;

	minus = 0;
	num = n;
	if (n < 0)
	{
		minus = -1;
		num *= -1;
	}
	if (minus == -1)
		arr[0] = '-';
	put_num(arr + (-1) * minus, num);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	n_arr[12];

	ft_bzero(n_arr, 12);
	ft_static_itoa(n_arr, n);
	write(fd, n_arr, ft_strlen(n_arr));
}
