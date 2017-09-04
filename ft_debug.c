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

static void	small_hex(unsigned char octet)
{
	ft_putchar('0');
	if (octet < 10)
		ft_putchar(octet + '0');
	else
		ft_putchar(octet + 87);
}

static void	print_hex(unsigned char octet)
{
	if (octet < 10)
		ft_putchar(octet + '0');
	else if (octet < 16)
		ft_putchar(octet + 87);
	else
	{
		print_hex(octet / 16);
		print_hex(octet % 16);
	}
}

void	show_hex(t_conv *conv)
{
	int				i;
	int				n;
	unsigned char	*num;

	ft_putstr("0x");
	if (conv->opcode < 16)
		small_hex(conv->opcode);
	else
		print_hex(conv->opcode);
	ft_putchar(' ');
	if (conv->hasencoding)
	{
		ft_putstr("0x");
		if (conv->encoding < 16)
			small_hex(conv->encoding);
		else
			print_hex(conv->encoding);
		ft_putchar(' ');
	}
	i = -1;
	while (++i < conv->n_params)
	{
		n = conv->b_param[i];
		num = (void*)&conv->param[i];
		while (--n >= 0)
		{
			ft_putstr("0x");
			if (num[n] < 16)
				small_hex(num[n]);
			else
				print_hex(num[n]);
			ft_putchar(' ');
		}
	}
	ft_putline();
}
