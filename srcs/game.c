#include <wolf.h>

void			move(t_env *env)
{
	if (env->player.v > 0)
		env->player.y += 0.5;
	else if (env->player.v < 0)
		env->player.y -= 0.5;
	if (env->player.t > 0)
		env->player.dir += 0.5;
	else if (env->player.t < 0)
		env->player.dir -= 0.5;
	while (env->player.dir > 360)
		env->player.dir -= 360;
	while (env->player.dir < 0)
		env->player.dir += 360;
}