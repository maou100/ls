#include "ft_ls"

int	is_dirs(char *path)
{
	struct stat	stats;

	if (stat(path, &stats) == -1)
		return (0);
	if (S_ISDIR(stats.st_mode))
		return (1);
	return (0);
}

t_paths	*process_dirs(t_paths *args, t_flags flags)
{
	t_paths		*dirs;
	t_paths		*prev;
	t_paths		*tmp;

	dirs = NULL;
	prev = NULL;
	while (args)
	{
		if (is_dirs(args->path))
		{
			if (prev)
				prev->next = args->next;
			tmp = args->next;
			args->next = dirs;
			dirs = args;
			args = tmp;
		}
		else
		{
			prev = args;
			args = args->next;
		}
	}
	if (dirs && dirs->next)
	{
		if (flag.t)
			dirs = time_sort(dirs);
		else
			dirs = ascii_sort(dirs);
		if (flags.r)
			dirs = reverse_list(dirs);
	}
	return (dirs);
}
