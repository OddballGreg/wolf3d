/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datahandling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:34:19 by sallen            #+#    #+#             */
/*   Updated: 2016/11/23 15:35:38 by sallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	init(t_env *env, char *filename)
{
	int			fd;
	int			x;
	char		*line;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_puterror("Cannot open file.");
	env->maph = -1;
	while (get_next_line(fd, &line) != 0)
	{
		x = -1;
		env->maph++;
		while (line[++x] != '\0')
		{
			MAP[env->maph][x] = line[x];
			if (MAP[env->maph][x] == '*')
			{
				PLAYER.pos_x = x;
				PLAYER.pos_y = env->maph;
			}
			if (env->mapw < x)
				env->mapw = x;
		}
	}
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
}

void	set_game(t_env *env)
{
	IMGPTR = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->endian);
	PLAYER.pos_x = 0;
	PLAYER.pos_y = 0;
	PLAYER.dir_x = 0;
	PLAYER.dir_y = 0;
	PLAYER.plane_x = 0;
	PLAYER.plane_y = 0;
	PLAYER.v = 0;
	PLAYER.t = 0;
}

int		safe_exit(void *e)
{
	t_env	*env;

	env = (t_env *)e;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}
