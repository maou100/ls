#include "ft_ls.h"

int	is_file(const char *path)
{
	struct stat	stats;

	stat(path, &stats);
	if (S_ISREG(stats.st_mode))
		return (1);
	return (0);
}

t_paths	*process_files(t_paths *args, t_flags flags)
{
	t_paths		*files;
	t_paths		*prev;
	t_paths		*tmp;

	files = NULL;
	prev = NULL;
	while (args)
	{
		if (is_file(args->path))
		{
			if (prev)
				prev->next = args->next;
			tmp = args->next;
			args->next = files;
			files = args;
			args = tmp;
			
		}
		else
		{
			prev = args;
			args = args->next;
		}
	}
	if (files && files->next)
	{
		if (flags.t)
			files = time_sort(files);
		else
			files = ascii_sort(files);
		if (flags.r)
			files = reverse_list(files);
	}
	return (files);
}
