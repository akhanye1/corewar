
#include "ft_corewar.h"

int	ft_sub(t_conv *instruct, int total_bytes)
{
	char	*defix;
	char	**split;
	char	*decode;
	int		i;

	if (!(defix = ft_strdefix(instruct->line, ' ')) || !(split = ft_strsplit(defix, ',')))
		return (0);
	if (!(instruct->opcode = ft_get_opcode("sub")))
		return (0);
	instruct->bytes = 2;
	instruct->hasencoding = 1;
	instruct->encoding = ft_get_encoding(instruct->line);
	instruct->n_params = 3;
	decode = ft_decoding(instruct->line, instruct->n_params);
	instruct->index = total_bytes + 1;
	fill_params(instruct, split, decode);
	i = -1;
	while (++i < instruct->n_params)
		instruct->bytes += instruct->b_param[i];
	return (1);
}
