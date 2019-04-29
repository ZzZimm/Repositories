/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:51:44 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/15 17:24:35 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define DRAW_LINE_H

typedef struct	s_aa_info
{
	float	gradient;
	float	xend;
	float	yend;
	float	xgap;
	float	intery;
	int		steep;
	int		is_edge;
	int		color;
}				t_aa_info;

#endif
