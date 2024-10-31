# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 16:57:09 by ade-fran          #+#    #+#              #
#    Updated: 2024/05/10 16:57:11 by ade-fran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			=	client

SERVER			=	server

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -I ${INCLD_DIR} -g 

RM 				=	rm -rf

# **************************************************************************** #
#                                                                              #
#                                  COLORS                                      #
#                                                                              #
# **************************************************************************** #

PURPLE 			=	\033[10;95m

GREEN			=	\033[0;32m

YELLOW			=	\033[0;33m

COLOUR_END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                                   LIBFT                                      #
#                                                                              #
# **************************************************************************** #

LIB				=	libft.a

LIBFT_FOLDER 	=	libft/

LIB_DIR			=	${LIBFT_FOLDER}lib/

LIB_SRC			=	${LIBFT_FOLDER}*/*.c

LIB_INCLD_DIR	=	${LIBFT_FOLDER}inc/

LIB_INCLD		= 	${LIB_INCLD_DIR}libft.h

LIB_PATH		=	$(addprefix ${LIB_DIR}, ${LIB})

# **************************************************************************** #
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
# **************************************************************************** #

SRC_CLIENT_PATH 	=	srcs/client/

SRC_SERVER_PATH		=	srcs/server/

SRC_CLIENT			=	client.c \
							client_utils/init_client_data.c \
							client_utils/client_errors.c \
							client_utils/exit_client.c \
							client_utils/manage_client.c \
							client_utils/get_serv_pid.c \
							client_utils/char_to_bits.c \
							client_utils/send_data.c \

SRC_SERVER			=	server.c \
							server_utils/bits_to_char.c \
							server_utils/set_sigaction.c \
							server_utils/sig_handler.c \

# **************************************************************************** #
#                                                                              #
#                                  OBJECTS                                     #
#                                                                              #
# **************************************************************************** #

OBJ_CLIENT_PATH		=	objs_client/

OBJ_SERVER_PATH		=	objs_server/

OBJ_CLIENT			=	$(addprefix ${OBJ_CLIENT_PATH}, ${SRC_CLIENT:.c=.o}) \

OBJ_SERVER			=	$(addprefix ${OBJ_SERVER_PATH}, ${SRC_SERVER:.c=.o}) \

# **************************************************************************** #
#                                                                              #
#                                  INCLUDES                                    #
#                                                                              #
# **************************************************************************** #

INCLD_DIR		=	./inc/

INCLD			=	${INCLD_DIR}minitalk.h

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all: ${CLIENT} ${SERVER}

${LIB_PATH}: ${LIB_SRC} ${LIB_INCLD}
	@make -C ${LIBFT_FOLDER} --no-print-directory
	@echo "${GREEN}\33[2K\nLibft compiled\n${COLOUR_END}"
	

${CLIENT}: ${LIB_PATH} ${OBJ_CLIENT} ${INCLD}
	@${CC} ${CFLAGS} ${OBJ_CLIENT} ${LIB_PATH} -o ${CLIENT}
	@echo "${GREEN}\33[2K\nClient compiled\n${COLOUR_END}"

${SERVER}: ${LIB_PATH} ${OBJ_SERVER} ${INCLD}
	@${CC} ${CFLAGS} ${OBJ_SERVER} ${LIB_PATH} -o ${SERVER}
	@echo "${GREEN}\33[2K\nServer compiled\n${COLOUR_END}"

${OBJ_CLIENT_PATH}%.o:	${SRC_CLIENT_PATH}%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@ && printf "\33[2K\r${YELLOW}Compiling Client :${COLOUR_END} $@" 

${OBJ_SERVER_PATH}%.o:	${SRC_SERVER_PATH}%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@ && printf "\33[2K\r${YELLOW}Compiling Server :${COLOUR_END} $@" 

clean:
	@${RM} ${OBJ_CLIENT_PATH}
	@${RM} ${OBJ_SERVER_PATH}
	@make clean -C ${LIBFT_FOLDER} --no-print-directory

fclean: clean
	@${RM} ${CLIENT}
	@${RM} ${SERVER}
	@make fclean -C ${LIBFT_FOLDER} --no-print-directory
	@echo "${GREEN}Client & Server cleaned\n${COLOUR_END}"

re:	fclean all

.PHONY: all clean fclean re
