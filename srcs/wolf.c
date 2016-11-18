#include <wolf.h>

int				main(int argc, char **argv)
{
	t_env		env;

	if (argc < 2)
		ft_puterror("Please pass a valid mapfile as an arguement.");
	init(&env, argv[1]);
	mlx_hook(env.win, 17, 0L, safe_exit, (void *)&env);
	mlx_loop(env.mlx);
}

void			init(t_env *env, char *filename)
{
	int			fd;
	int			y;
	int			x;
	char		*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_puterror("Cannot open file.");
	x = -1;
	y = -1;
	while (get_next_line(fd, &line) != 0)
	{
		y++;
		while (//loop through string)
	}
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
}

int			safe_exit(void *env)
{
	t_env	*nenv;
	int		index;

	nenv = (t_env *)env;
	index = -1;
	while (nenv->map[++index] != NULL)
		free(nenv->map[index]);
	free(nenv->map);
	mlx_destroy_image(nenv->mlx, nenv->img);
	mlx_destroy_window(nenv->mlx, nenv->win);
	exit(0);
	return (0);
}