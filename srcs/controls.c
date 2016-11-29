/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:35:06 by sallen            #+#    #+#             */
/*   Updated: 2016/11/29 10:35:08 by sallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int			key_press(int keycode, t_env *e)
{
	if (keycode == 123 || keycode == 86)
		e->player.move.left = 1;
	if (keycode == 126 || keycode == 91)
		e->player.move.up = 1;
	if (keycode == 124 || keycode == 88)
		e->player.move.right = 1;
	if (keycode == 125 || keycode == 84)
		e->player.move.down = 1;
	return (0);
}

int			key_release(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 123 || keycode == 86)
		e->player.move.left = 0;
	if (keycode == 126 || keycode == 91)
		e->player.move.up = 0;
	if (keycode == 124 || keycode == 88)
		e->player.move.right = 0;
	if (keycode == 125 || keycode == 84)
		e->player.move.down = 0;
	return (0);
}

static void	turn(t_env *e, char dir)
{
	double	tmpdir;
	double	tmpplain;
	int		coef;

	coef = 1;
	tmpdir = e->player.dir.x;
	tmpplain = e->r.plain.x;
	if (dir == '1')
		coef = -1;
	e->player.dir.x = e->player.dir.x * cos(coef * e->player.rspeed)
		- e->player.dir.y * sin(coef * e->player.rspeed);
	e->player.dir.y = tmpdir * sin(coef * e->player.rspeed) + e->player.dir.y
		* cos(coef * e->player.rspeed);
	e->r.plain.x = e->r.plain.x * cos(coef * e->player.rspeed)
		- e->r.plain.y * sin(coef * e->player.rspeed);
	e->r.plain.y = tmpplain * sin(coef * e->player.rspeed)
		+ e->r.plain.y * cos(coef * e->player.rspeed);
}

void		move(t_env *e)
{
	if (e->player.move.up)
	{
		if (!(e->map.map[(int)(e->player.pos.x + e->player.dir.x
						* e->player.mspeed)][(int)(e->player.pos.y)]))
			e->player.pos.x += e->player.dir.x * e->player.mspeed;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y
						+ e->player.dir.y * e->player.mspeed)]))
			e->player.pos.y += e->player.dir.y * e->player.mspeed;
	}
	if (e->player.move.left)
		turn(e, '0');
	if (e->player.move.right)
		turn(e, '1');
	if (e->player.move.down)
	{
		if (!(e->map.map[(int)(e->player.pos.x - e->player.dir.x *
						e->player.mspeed)][(int)(e->player.pos.y)]))
			e->player.pos.x -= e->player.dir.x * e->player.mspeed;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y -
						e->player.dir.y * e->player.mspeed)]))
			e->player.pos.y -= e->player.dir.y * e->player.mspeed;
	}
}
