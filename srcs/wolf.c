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

int		main(int argc, char **argv)
{
	t_env	e;

	(void)argc;
	e.mlx = mlx_init();
	if ((e.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3d");
	e.img.img = NULL;
	e.player.pos.x = 4;
	e.player.pos.y = 4;
	e.player.dir.x = -1;
	e.player.dir.y = 0;
	e.r.plain.x = 0;
	e.r.plain.y = 0.80;
	e.time = 0;
	e.oldtime = 0;
	readfile(&e, argv[1]);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
	mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
	mlx_hook(e.win, 17, 0L, ft_esc, &e);
	mlx_loop(e.mlx);
	return (0);
}
