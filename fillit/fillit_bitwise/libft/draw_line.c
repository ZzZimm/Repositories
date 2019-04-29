/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:04:55 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/15 17:17:26 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw_line.h"
#include <math.h>
#include <mlx.h>

static void	update_info(t_aa_info *info, float x, float y, int nb_edge)
{
	info->xend = round(x);
	info->yend = y + info->gradient * (info->xend - x);
	info->xgap = nb_edge == 0 ? rfpart(x + 0.5) : fpart(x + 0.5);
}

static void	draw_line_edge(t_win win, t_aa_info info)
{
	int x;
	int y;
	int color_1;
	int color_2;

	x = info.xend;
	y = ipart(info.yend);
	color_1 = br_adjust(info.color, rfpart(info.yend) * info.xgap);
	color_2 = br_adjust(info.color, fpart(info.yend) * info.xgap);
	if (info.steep)
	{
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, y, x, color_1);
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, y + 1, x, color_2);
	}
	else
	{
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y, color_1);
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y + 1, color_2);
	}
}

static void	draw_line_middle(t_win win, t_aa_info info, float x0)
{
	int		x;
	float	i_y;

	x = round(x0);
	i_y = info.intery;
	if (info.steep)
		while (x < info.xend)
		{
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ipart(i_y), x,
				br_adjust(info.color, rfpart(i_y)));
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ipart(i_y) + 1, x,
					br_adjust(info.color, fpart(i_y)));
			i_y += info.gradient;
			x++;
		}
	else
		while (x < info.xend)
		{
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, ipart(i_y),
					br_adjust(info.color, rfpart(i_y)));
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, ipart(i_y) + 1,
					br_adjust(info.color, fpart(i_y)));
			i_y += info.gradient;
			x++;
		}
}

void		draw_line(t_win win, t_point l0, t_point l1, int color)
{
	t_aa_info	info;

	info.color = color;
	info.steep = fabs(l1.y - l0.y) > fabs(l1.x - l0.x);
	if (info.steep)
	{
		swap(&l0.x, &l0.y);
		swap(&l1.x, &l1.y);
	}
	if (l0.x > l1.x)
	{
		swap(&l0.x, &l1.x);
		swap(&l0.y, &l1.y);
	}
	info.gradient = (l1.x != l0.x) ? (l1.y - l0.y) / (l1.x - l0.x) : 1.0;
	update_info(&info, l0.x, l0.y, 0);
	draw_line_edge(win, info);
	info.intery = info.yend + info.gradient;
	update_info(&info, l1.x, l1.y, 1);
	draw_line_edge(win, info);
	draw_line_middle(win, info, l0.x);
}
