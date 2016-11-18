#include <wolf.h>

int				main(int argc, char **argv)
{
	t_env		env;

	if (argc < 2)
		ft_puterror("Please pass a valid mapfile as an arguement.");
	env.mlx = mlx_init();
	init(&env, argv[1]);
	mlx_hook(env.win, 17, 0L, safe_exit, (void *)&env);
	mlx_loop(env.mlx);
}

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
				env->player.x = x;
				env->player.y = env->maph;
			}
			if (env->mapw < x)
				env->mapw = x;
		}
	}
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
}

int			safe_exit(void *env)
{
	t_env	*nenv;

	nenv = (t_env *)env;
	mlx_destroy_image(nenv->mlx, nenv->img);
	mlx_destroy_window(nenv->mlx, nenv->win);
	exit(0);
	return (0);
}