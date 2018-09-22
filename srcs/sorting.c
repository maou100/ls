#include "ft_ls"

t_paths		*time_sort(t_paths *files)
{
	t_paths	*tmp;
	char	*buf;

	while (files)
	{
		tmp = files;
		if (time_cmp(tmp, files->next))
			files = files->next;
		else
		{
			buf = tmp->path;
			tmp->path = (files->next)->path;
			(files->next)->path = buf;
		}
	}
}
