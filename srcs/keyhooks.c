#include <wolf.h>

int 			key_press(int key, void *e)
{
	t_env	*env;

	env = (t_env *)e;
	if (key == KEY_UP)
		env->player.v = VELOCITY;
	else if (key == KEY_DOWN)
		env->player.v = -VELOCITY;
	else if (key == KEY_LEFT)
		env->player.t = -TORQUE;
	else if (key == KEY_RIGHT)
		env->player.t = TORQUE;
	else if (key == KEY_ESC)
		safe_exit(e);
	printf("x: %f, y: %f, dir: %f\n", env->player.x, env->player.y, env->player.dir);
	return (0);
}

int 			key_release(int key, void *e)
{
	t_env	*env;

	env = (t_env *)e;
	if (key == KEY_UP || key == KEY_DOWN)
		env->player.v = 0;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		env->player.t = 0;
	printf("x: %f, y: %f, dir: %f\n", env->player.x, env->player.y, env->player.dir);
	return (0);
}