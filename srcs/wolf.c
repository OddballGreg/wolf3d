#include <wolf.h>

int				main(int argc, char **argv)
{
	t_env		env;

	if (argc < 2)
		ft_puterror("Please pass a valid mapfile as an arguement.");
	env.mlx = mlx_init();
	init(&env, argv[1]);
	env.player.x = 0; //Db
	env.player.y = 0; //db
	env.player.dir = 0; //db
	mlx_do_key_autorepeatoff(env.mlx);
	mlx_hook(env.win, 2, 1, &key_press, (void *)&env);
	mlx_hook(env.win, 3, 2, &key_release, (void *)&env);
	mlx_hook(env.win, 17, 0L, safe_exit, (void *)&env);
	mlx_loop_hook(env.mlx, run, (void *)&env);
	mlx_loop(env.mlx);
}

int				run(void *e)
{
	t_env	*env;

	env = (t_env *)e;
	move(env);
	draw(env);
	return (0);
}

