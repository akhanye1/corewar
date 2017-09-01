# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhanye <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 10:25:20 by akhanye           #+#    #+#              #
#    Updated: 2017/08/29 10:57:25 by pamashil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	makeinstall
ASSEMBLER	=	asm
VIRTUAL		=	push_swap

SRC_ASM		=	main.c					\
				ft_fileok.c				\
				opcode.c				\
				ft_write.c				\
				ft_decoding.c			\
				ft_params.c				\
				ft_get_encoding.c		\
				ft_labels.c				\
				convert.c				\
				ft_lfork.c				\
				ft_fork.c				\
				ft_sti.c				\
				ft_live.c				\
				ft_and.c				\
				ft_lldi.c				\
				ft_or.c					\
				ft_xor.c				\
				ft_ld.c					\
				ft_st.c					\
				ft_add.c				\
				ft_sub.c				\
				ft_zjmp.c				\
				ft_ldi.c				\
				ft_lld.c				\
				ft_aff.c				\
				ft_getbytes.c			\
				ft_debug.c				\
				numberconversion.c		\
				ft_tabs.c

#SRC_PUSHS	= 	push_s.c				\
				dosort.c

#SRC_ALL		=	error_check.c			\
				instructions.c			\
				addtostack.c			\
				operations.c			\
				swap_instruction.c		\
				rotate_operation.c		\
				debug.c					\
				rrotate_operation.c		\
				push_operation.c		\
				sortcheck.c				\
				smartsort.c				\
				sortchecka.c			\
				combine_inst.c			\
				breakup.c				\
				moreinfo.c				\
				small.c					\
				large.c					\
				sortcheckb.c			\
				median.c

FLAGS	=  -Wall -Wextra -Werror

LIBRARY =	-L libft -lft

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) $(SRC_ASM) $(LIBRARY) -o $(ASSEMBLER)
	#clang $(FLAGS) -g $(SRC_ALL) $(SRC_PUSHS) $(LIBRARY) -o $(PUSH_SWAP)


clean:
	make -C libft/ clean
	#rm -f $(OBJ_CHECKER)

fclean: clean
	make -C libft/ fclean
	rm -f $(ASSEMBLER) $(VIRTUAL)

re: 	fclean all
