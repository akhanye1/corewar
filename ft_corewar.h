/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 23:40:00 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/25 11:04:13 by jngoma           ###   ########.fr       */
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
	struct	s_conv	*next;
	struct	s_conv	*prev;
}					t_conv;

typedef struct		s_label
{
	char			*name;
	int				index;
	struct	s_label	*next;
}					t_label;

typedef struct		s_asm
{
	t_conv		*line;
	header_t	header;
}					t_asm;

int				ft_fileok(char *filename);
unsigned char	ft_get_opcode(char *str);
void			write_to_cor(t_asm *data);
int				convert_file(int fd);
int				ft_get_dir(char *val);
int				ft_get_ind(char *val);
int				ft_get_reg(char *val);
int				ft_sti(t_conv *instruct);
int				ft_or(t_conv *instruct);
char			*ft_decoding(char *str);
unsigned char	ft_get_encoding(char *str);
unsigned char	bintodec(char *bin_no);
int         	ft_is_label_only(char *line);
int         	ft_contains_label(char *line);
t_label     	*create_label(char **line, int total_bytes);
void			add_label(t_label **label, t_label *newlabel);
#endif
