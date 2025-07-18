/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_varg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:04:09 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:06:38 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_set.h"
#include "manage_varg.h"
#include "handle_error.h"
#include "libft.h"

void	set_varg(t_parse_set **vlist_p, va_list args)
{
	size_t		i;
	t_parse_set	*vlist_set;
	t_data		arg;

	i = 0;// arg type 매개변수로 받아와서 제일 큰 값으로 arg 해석 하기
	while (vlist_p[i])
	{
		vlist_set = vlist_p[i];
		
		i++;
	}
}

bool	valid_varg(t_parse_set **vlist_p)
{
	size_t		i;
	uint8_t		va_flag;
	t_parse_set	*vlist_set;
	//여기서 flag에 arg type 저장 후 리턴

	i = 0;
	va_flag = 0;
	while (vlist_p[i])
	{
		vlist_set = vlist_p[i];
		if (vlist_set->pos_width || vlist_set->pos_precision)
			va_flag |= flag_num;
		if (ft_strcmp(vlist_set->conv_type, "s"))
			va_flag |= flag_str;
		if ((va_flag & flag_num) && (va_flag & flag_str))
			return (false);
		// 에러 체크는 나가서 하고 arg type 저장만 하기
		i++;
	}
	return (true);
}

int	manage_args(va_list args, t_parse_set ***vlist, size_t vlist_size)
{
	size_t		i;
	t_parse_set	**vlist_p;

	i = 0;
	while (i < vlist_size)
	{
		vlist_p = vlist[i];
		if (!valid_varg(vlist_p))
			return (invlaid_varg);
		set_varg(vlist_p, args); ///
		i++;
	}
	vlist_free(vlist, vlist_size);
	return (0);
}
