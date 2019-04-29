/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:08:51 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/24 18:42:29 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "fillit.h"

int		get_line_len(char *str);
int		lines_ok(char *str, int nb_read);
int		piece_ok(char *buf);
void	store_buf(char *buf, t_tetris *pieces);
void	get_info(t_tetris *pieces);

#endif
