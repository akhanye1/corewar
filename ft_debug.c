#include "ft_corewar.h"

void	show_conv_before(char *line)
{
	ft_putstr(line);
	ft_putstr(" > ");
}

void	show_buffer_after(t_conv *line)
{
	ft_putstr("\t");
	ft_putstr(line->line);
	ft_putline();
}
