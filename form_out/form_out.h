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

#ifndef FORM_OUT_H
# define FORM_OUT_H

# include "basic_struct.h"

/* Main formatting function */
char	*construct_final_output(t_parse_set *head);

/* format_conversions */
char	*format_char(t_parse_set *set);
char	*format_string(t_parse_set *set);
char	*format_pointer(t_parse_set *set);
char	*format_integer(t_parse_set *set);
char	*format_unsigned(t_parse_set *set);
char	*format_hex(t_parse_set *set, int up);
char	*format_percent(t_parse_set *set);

/* format_utils */
char	*apply_width(char *str, t_parse_set *set);
char	*apply_precision(char *str, t_parse_set *set);
char	*apply_flags(char *str, t_parse_set *set);
char	*ft_itoa_base(long long n, int base, int uppercase);
char	*ft_utoa_base(unsigned long long n, int base, int uppercase);

/* format_helpers */
long long		get_int_value(t_parse_set *set);
unsigned long long	get_uint_value(t_parse_set *set);
char		*get_formatted_string(t_parse_set *cur);
void		copy_conv_data(char *res, t_parse_set *cur, size_t *pos);

/* format_flag_helpers */
char		*apply_sign_to_int(char *str, t_parse_set *set, long long val);
char		*apply_hash_to_hex(char *str, t_parse_set *set,
			unsigned long long val, int up);

/* format_padding_helpers */
char		get_padding_char(t_parse_set *set);
void		do_left_pad(char *res, char *str, int w, char pad);
void		do_right_pad(char *res, char *str, int w, char pad);

/* format_itoa_helpers */
int		calc_itoa_base_len(long long n, int base, int neg);
void		fill_itoa_base_digits(char *res, long long n, int base, int pos);
int		calc_utoa_base_len(unsigned long long n, int base);
void		fill_utoa_digits(char *res, unsigned long long n, int base,
			int len);

#endif
