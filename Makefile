# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhanye <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 10:25:20 by akhanye           #+#    #+#              #
#    Updated: 2017/08/21 10:34:20 by akhanye          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	makeinstall
ASSEMBLER	=	asm
VIRTUAL		=	push_swap

SRC_ASM		=	main.c					\
				ft_fileok.c				\
				ft_write.c				\
				convert.c

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
