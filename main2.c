#include <stdio.h>
#include "ft_corewar.h"

int main()
{
	t_op optab;

	optab = op_tab;
	for (int i = 0; i < 16 ; i++)
	{
		printf("%s",optab[i]);
	}
}
