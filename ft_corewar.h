/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 23:40:00 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/23 09:55:56 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "op.h"
# include "libft/libft.h"

typedef struct		s_conv
{
	char			*line;
	unsigned char	*idata;
	int				fileindex;
	int				bytes;
	char			haslabel;
}					t_conv;

typedef struct		s_label
{
	char			*name;
	int				value;
	int				index;
}					t_label;

typedef struct		s_asm
{
	struct s_conv	*conv;
	struct header_s	header;
}					t_asm;

int				ft_fileok(char *filename);
unsigned char	ft_get_opcode(char *str);
void	write_to_cor(t_asm *data);
int		convert_file(int fd);

#endif
