/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_out.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_OUT
# define FORM_OUT

#include "basic_struct.h"

/* Main formatting function */
char	*construct_final_output(t_parse_set *head);

/* format_conversions */
char	*format_char(t_parse_set *set);
char	*format_string(t_parse_set *set);
char	*format_pointer(t_parse_set *set);
char	*format_integer(t_parse_set *set);
char	*format_unsigned(t_parse_set *set);
char	*format_hex(t_parse_set *set, int uppercase);
char	*format_percent(t_parse_set *set);

/* format_utils */
char	*apply_width(char *str, t_parse_set *set);
char	*apply_precision(char *str, t_parse_set *set);
char	*apply_flags(char *str, t_parse_set *set);
char	*ft_itoa_base(long long n, int base, int uppercase);
char	*ft_utoa_base(unsigned long long n, int base, int uppercase);

#endif
