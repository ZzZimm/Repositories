/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:25:44 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/14 18:52:46 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"

int		rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

/*
** return rgb int of a pixel with adjusted brightness
** where 0 < brightness < 1
*/

int		br_adjust(int rgb_int, float brightness)
{
	int red;
	int green;
	int blue;

	blue = (0xFF & rgb_int) * brightness;
	green = (0xFF & (rgb_int >> 8)) * brightness;
	red = (rgb_int >> 16) * brightness;
	return (rgb(red, green, blue));
}
