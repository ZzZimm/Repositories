/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 22:58:25 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/24 18:43:03 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "fillit.h"
# include <sys/types.h>
# define BIT 9223372036854775808ULL

/*
**BIT = 0b1000000000000000000000000000000000000000000000000000000000000000
*/
void	set_bit(u_int64_t *nb, int pos);
void	print_sol(t_tetris *pieces, int size);
int		get_next_offset(char *buf);
int		get_offset(char **buf);
void	reverse_pieces_bytes(t_tetris *pieces);

#endif
