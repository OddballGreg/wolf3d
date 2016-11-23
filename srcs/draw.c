/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:42:20 by sallen            #+#    #+#             */
/*   Updated: 2016/11/23 15:42:23 by sallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void    draw(t_env *env)
{
		//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
		if (RAY.side == 0)
            RAY.perp_wall_dist = (PLAYER.box_x - RAY.pos_x + (1 - PLAYER.step_x) / 2) / RAY.dir_x;
		else
            RAY.perp_wall_dist = (PLAYER.box_y - RAY.pos_y + (1 - PLAYER.step_y) / 2) / RAY.dir_y;

		//Calculate height of line to draw on screen
		RAY.line_height = (int)(HEIGHT / RAY.perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		RAY.draw_start = -RAY.line_height / 2 + HEIGHT / 2;
		if (RAY.draw_start < 0)
            RAY.draw_start = 0;
		RAY.draw_end = RAY.line_height / 2 + HEIGHT / 2;
		if (RAY.draw_end >= HEIGHT)
            RAY.draw_end = HEIGHT - 1;
}

void	put_pixel(t_env *env, int x, int y, unsigned int colour)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (colour & 0xFF0000) >> 16;
	g = (colour & 0x00FF00) >> 8;
	b = (colour & 0x0000FF);
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		env->imgptr[((y * WIDTH * env->bpp) >> 3)
			+ ((env->bpp >> 3) * x)] = b;
		env->imgptr[((y * WIDTH * env->bpp) >> 3)
			+ ((env->bpp >> 3) * x) + 1] = g;
		env->imgptr[((y * WIDTH * env->bpp) >> 3)
			+ ((env->bpp >> 3) * x) + 2] = r;
	}
}
