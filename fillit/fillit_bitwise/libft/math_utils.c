/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:02:29 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/14 18:55:17 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int		ipart(float x)
{
	return (floor(x));
}

float	fpart(float x)
{
	return (x - floor(x));
}

float	rfpart(float x)
{
	return (1 - fpart(x));
}
