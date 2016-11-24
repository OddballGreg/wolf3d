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

void	render(t_env *env)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		transform_init(env);
		transform_move(env);
		transform_dda(env);
		draw(env);
		put_pixel(env, x, 12, 0xFF0000);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
void	transform_init(t_env *env)
{
	/*
		Calculate direction of ray relative to position of player and camera coords
	*/

	CAMERA.pos_x = 2 * PLAYER.pos_x / (double)WIDTH - 1;	//x-coord of camera at FOV(x)
	RAY.pos_x = PLAYER.pos_x;
	RAY.pos_y = PLAYER.pos_y;
	RAY.dir_x = PLAYER.dir_x + PLAYER.plane_x * CAMERA.pos_x;
	RAY.dir_y = PLAYER.dir_y + PLAYER.plane_y * CAMERA.pos_x;
	
	//which box of the map we're in
	PLAYER.box_x = (int)RAY.pos_x;
	PLAYER.box_y = (int)RAY.pos_y;

	//length of ray from one x or y-side to next x or y-side
	RAY.delta_dist_x = sqrt(1 + (RAY.dir_y * RAY.dir_y) / (RAY.dir_x * RAY.dir_x));
	RAY.delta_dist_y = sqrt(1 + (RAY.dir_x * RAY.dir_x) / (RAY.dir_y * RAY.dir_y));
	
	HIT = 0; //was there a wall hit?
}

void	transform_move(t_env *env)
{
	//calculate step and initial sideDist
	if (RAY.dir_x < 0)
	{
		PLAYER.step_x = -1;
		RAY.side_dist_x = (RAY.pos_x - PLAYER.box_x) *RAY.delta_dist_x;;
	}
	else
	{
		PLAYER.step_x = 1;
		RAY.side_dist_x = (PLAYER.box_x + 1.0 - RAY.pos_x) *RAY.delta_dist_x;;
	}
	if (RAY.dir_y < 0)
	{
		PLAYER.step_y = -1;
		RAY.side_dist_y = (RAY.pos_y - PLAYER.box_y) * RAY.delta_dist_y;
	}
	else
	{
		PLAYER.step_y = 1;
		RAY.side_dist_y = (PLAYER.box_y + 1.0 - RAY.pos_y) * RAY.delta_dist_y;
	}
}
		
void	transform_dda(t_env *env)
{		//perform DDA }
	while (HIT == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (RAY.side_dist_x < RAY.side_dist_y)
		{
			RAY.side_dist_x +=RAY.delta_dist_x;;
			PLAYER.box_x += PLAYER.step_x;
			RAY.side = 0;
		}
		else
		{
			RAY.side_dist_y += RAY.delta_dist_y;
			PLAYER.box_y += PLAYER.step_y;
			RAY.side = 1;
		}
		//Check if ray has hit a wall
		if (MAP[(int)PLAYER.box_x][(int)PLAYER.box_y] > 0)
			HIT = 1;
	}
}
