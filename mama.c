#include "ft_corewar.h"

int main()
{
	char *str = "hi	im	awesome	d";
	char **splt = ft_strsplit(str, '\t');
	printf("%s\n", splt[0]);
	return (0);
}
