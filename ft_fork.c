int	ft_fork(t_conv **instruct, int total_bytes, t_label *labels)
{
	char *defix;
	char **split;
	int	i;

	if(!(defix = ft_strdefix((*instruct)->line, ' ')) || !(split = ft_strsplit(defix, ',')))
		return(0);
	if(!((*instruct)->opcode = ft_get_opcode("fork")))
		return(0);
	(*instruct)->bytes = 1;
	(*instruct)->haslabel = 1;
	(*instruct)->hasencoding = 0;
	(*instruct)->n_params = 1;
	(*instruct)->index = total_bytes + 1;
	ft_decoding(instruct);
	fill_params(instruct, split, labels);
	i = -1;
	while(++i < (*instruct)->n_params)
		(*instruct)->bytes += (*instruct)->b_params[i];
	return (1);
}
