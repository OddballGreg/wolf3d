/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:39:40 by sallen            #+#    #+#             */
/*   Updated: 2016/11/23 15:39:43 by sallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			move(t_env *env)
{
	if (PLAYER.t > 0)
		PLAYER.dir += TORQUE;
	else if (PLAYER.t < 0)
		PLAYER.dir -= TORQUE;
	while (PLAYER.dir > 360)
		PLAYER.dir -= 360;
	while (PLAYER.dir < 0)
		PLAYER.dir += 360;
	if (PLAYER.v > 0)
	{
		PLAYER.pos_y += VELOCITY * sin(PLAYER.dir);
		PLAYER.pos_x += VELOCITY * cos(PLAYER.dir);
	}
	else if (PLAYER.v < 0)
	{
		PLAYER.pos_y -= VELOCITY * sin(PLAYER.dir);
		PLAYER.pos_x -= VELOCITY * cos(PLAYER.dir);
	}
}
