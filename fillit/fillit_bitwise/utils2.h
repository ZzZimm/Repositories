/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:23:41 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/24 18:29:10 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H
# define UTILS2_H
# include <sys/types.h>

int		get_next_offset(char *buf);
int		get_offset(char **buf);
int		val(u_int64_t nb, int bit_pos);

#endif
