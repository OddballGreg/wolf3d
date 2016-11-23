#include <wolf.h>

void			init(t_env *env, char *filename)
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
			env->map[env->maph][x] = line[x];
			if (env->map[env->maph][x] == '*')
			{
				env->player.pos_x = x;
				env->player.pos_y = env->maph;
			}
			if (env->mapw < x)
				env->mapw = x;
		}
	}
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
}

void        set_game(t_env *env)
{
    env->imgptr = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->endian);
    env->player.pos_x = 0;
	env->player.pos_y = 0;
	env->player.dir_x = 0;
    env->player.dir_y = 0;
	env->player.plane_x = 0;
    env->player.plane_y = 0;
    env->player.v = 0;
	env->player.t = 0;

}

int			safe_exit(void *e)
{
	t_env	*env;

	env = (t_env *)e;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}
