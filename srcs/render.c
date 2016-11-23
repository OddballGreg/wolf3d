/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:42:20 by sallen            #+#    #+#             */
/*   Updated: 2016/11/23 15:42:23 by sallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	draw(t_env *env)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		/*
			Calculate direction of ray relative to position of player and camera coords
		*/

		CAMERA.pos_x = 2 * x / double(WIDTH) - 1;	//x-coord of camera at FOV(x)
		RAY.pos_x = PLAYER.pos_x;
		RAY.pos_y = PLAYER.pos_y;
		RAY.dir_x = PLAYER.dir_x + PLAYER.plane_x * CAMERA.pos_x;
		RAY.dir_y = PLAYER.dir_y + PLAYER.plane_y * CAMERA.pos_x;
		

		//which box of the map we're in
		MAP.box_x = int(RAY.pos_x);
		MAP.box_y = int(RAY.pos_y);

		//length of ray from current position to next x or y-side


		//length of ray from one x or y-side to next x or y-side
		env->delta_dist_x = sqrt(1 + (RAY.dir_y * RAY.dir_y) / (rayDirX * rayDirX));
		env->delta_dist_y = sqrt(1 + (rayDirX * rayDirX) / (RAY.dir_y* RAY.dir_y);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		
		put_pixel(env, x, 12, 0xFF0000);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
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
