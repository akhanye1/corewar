
#include "ft_corewar.h"

void	remove_tabs(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
	}
}
