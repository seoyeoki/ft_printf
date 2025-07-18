/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_varg.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:27:40 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 04:43:46 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_VARG
# define MANAGE_VARG

#include <stdarg.h>

typedef union u_data {
	char				ci;
	unsigned char		uci;
	short				si;
	unsigned short		usi;
	int					i;
	unsigned int		ui;
	long				l;
	unsigned long		ul;
	long long			ll;
	unsigned long long	ull;
	intmax_t			im_t;
	uintmax_t			uim_t;
	size_t				s_t;
	ptrdiff_t			pd_t;
	char				*s;
	void				*p;
} t_data;

#define flag_num (1 << 0)
#define flag_str (1 << 1)

#endif
