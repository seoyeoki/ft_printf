/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.h                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FORMAT_H
# define PARSE_FORMAT_H

# include "basic_struct.h"

void	parse_format(const char *format, t_parse_set **head, \
			t_parse_set **tail);

#endif