/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 23:40:00 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/24 12:32:21 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "op.h"
# include "libft/libft.h"

typedef struct		s_conv
{
	char			*line;
	unsigned char	*data;
	int				bytes;
	char			haslabel;
	unsigned char	opcode;
	char			hasencoding;
	unsigned char	encoding;
	char			n_params;
	char			b_param[3];
	int				param[3];
	struct s_conv	*next;
	struct s_conv	*prev;
}					t_conv;

typedef struct		s_label
{
	char			*name;
	int				value;
	int				index;
}					t_label;

typedef struct		s_asm
{
	struct s_conv	*line;
	struct header_s	header;
}					t_asm;

int				ft_fileok(char *filename);
unsigned char	ft_get_opcode(char *str);
void			write_to_cor(t_asm *data);
int				convert_file(int fd);
int				ft_get_dir(char *val);
int				ft_get_ind(char *val);
int				ft_get_reg(char *val);
int				ft_sti(t_conv *instruct);
char			*ft_decoding(char *str);
unsigned char	ft_get_encoding(char *str);
unsigned char	bintodec(char *bin_no);

#endif
