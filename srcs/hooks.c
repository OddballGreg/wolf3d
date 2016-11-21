#include <wolf.h>

int		ps_fw(void *env)
{
    t_env	*envp;

    ft_putendl("Up Arrow Pressed");
	envp = (t_env *)env;
    return (0);
}

int		ps_bw(void *env)
{
    t_env	*envp;

    ft_putendl("Down Arrow Pressed");
	envp = (t_env *)env;
    return (0);
}

int		ps_l(void *env)
{
    t_env	*envp;

    ft_putendl("Left Arrow Pressed");
	envp = (t_env *)env;
    return (0);
}

int		ps_r(void *env)
{
    t_env	*envp;

    ft_putendl("Right Arrow Pressed");
	envp = (t_env *)env;
    return (0);
}

int		ps_esc(void *env)
{
    t_env	*envp;

    ft_putendl("Esc Pressed");
	envp = (t_env *)env;
    return (0);
}