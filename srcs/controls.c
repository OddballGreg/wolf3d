/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:29:42 by ghavenga          #+#    #+#             */
/*   Updated: 2016/11/29 13:29:45 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int			key_press(int keycode, t_env *e)
{
	if LEFT
		PLAYER.move.left = 1;
	if FORWARD
		PLAYER.move.up = 1;
	if RIGHT
		PLAYER.move.right = 1;
	if BACK
		PLAYER.move.down = 1;
	return (0);
}

int			key_release(int keycode, t_env *e)
{
	if EXIT
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_SUCCESS);
	}
	if LEFT
		PLAYER.move.left = 0;
	if FORWARD
		PLAYER.move.up = 0;
	if RIGHT
		PLAYER.move.right = 0;
	if BACK
		PLAYER.move.down = 0;
	return (0);
}

static void	turn(t_env *e, char dir)
{
	double	tmpdir;
	double	tmpplain;
	int		coef;

	coef = 1;
	tmpdir = PLAYER.dir.x;
	tmpplain = e->r.plain.x;
	if (dir == '1')
		coef = -1;
	PLAYER.dir.x = PLAYER.dir.x * cos(coef * PLAYER.rspeed)
		- PLAYER.dir.y * sin(coef * PLAYER.rspeed);
	PLAYER.dir.y = tmpdir * sin(coef * PLAYER.rspeed) + PLAYER.dir.y
		* cos(coef * PLAYER.rspeed);
	e->r.plain.x = e->r.plain.x * cos(coef * PLAYER.rspeed)
		- e->r.plain.y * sin(coef * PLAYER.rspeed);
	e->r.plain.y = tmpplain * sin(coef * PLAYER.rspeed)
		+ e->r.plain.y * cos(coef * PLAYER.rspeed);
}

void		move(t_env *e)
{
	if (PLAYER.move.up)
	{
		if (!(MAP.map[(int)(PLAYER.pos.x + PLAYER.dir.x
						* PLAYER.mspeed)][(int)(PLAYER.pos.y)]))
			PLAYER.pos.x += PLAYER.dir.x * PLAYER.mspeed;
		if (!(MAP.map[(int)(PLAYER.pos.x)][(int)(PLAYER.pos.y
						+ PLAYER.dir.y * PLAYER.mspeed)]))
			PLAYER.pos.y += PLAYER.dir.y * PLAYER.mspeed;
	}
	if (PLAYER.move.left)
		turn(e, '0');
	if (PLAYER.move.right)
		turn(e, '1');
	if (PLAYER.move.down)
	{
		if (!(MAP.map[(int)(PLAYER.pos.x - PLAYER.dir.x *
						PLAYER.mspeed)][(int)(PLAYER.pos.y)]))
			PLAYER.pos.x -= PLAYER.dir.x * PLAYER.mspeed;
		if (!(MAP.map[(int)(PLAYER.pos.x)][(int)(PLAYER.pos.y -
						PLAYER.dir.y * PLAYER.mspeed)]))
			PLAYER.pos.y -= PLAYER.dir.y * PLAYER.mspeed;
	}
}
