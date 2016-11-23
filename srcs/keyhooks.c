/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:40:17 by sallen            #+#    #+#             */
/*   Updated: 2016/11/23 15:40:19 by sallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int		key_press(int key, void *e)
{
	t_env	*env;

	env = (t_env *)e;
	if (key == KEY_UP)
		PLAYER.v = VELOCITY;
	else if (key == KEY_DOWN)
		PLAYER.v = -VELOCITY;
	else if (key == KEY_LEFT)
		PLAYER.t = -TORQUE;
	else if (key == KEY_RIGHT)
		PLAYER.t = TORQUE;
	else if (key == KEY_ESC)
		safe_exit(e);
	return (0);
}

int		key_release(int key, void *e)
{
	t_env	*env;

	env = (t_env *)e;
	if (key == KEY_UP || key == KEY_DOWN)
		PLAYER.v = 0;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		PLAYER.t = 0;
	return (0);
}
