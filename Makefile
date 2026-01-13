# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME        := parser_test
CC          := clang
CFLAGS      := -Wall -Wextra -Werror

# dirs
SRCDIR      := src
LIBFT_DIR   := libft
GNL_DIR     := get_next_line

# include paths (ここがポイント: src から libft.h / gnl.h を見つける)
INCS        := -I$(SRCDIR) -I$(LIBFT_DIR) -I$(GNL_DIR)
CFLAGS      += $(INCS)

# libft
LIBFT       := $(LIBFT_DIR)/libft.a

# -----------------------------------------------------------------------------#
# sources
#   - src/*.c をまとめて拾う（wildcard）
#   - mlx/exec などを混ぜたくない場合は EXCLUDE で弾く
# -----------------------------------------------------------------------------#

SRC_ALL     := $(wildcard $(SRCDIR)/*.c)
GNL_SRCS    := $(wildcard $(GNL_DIR)/*.c)

# 必要なら除外（例: 本体用mainやmlx依存ファイルが src にある場合）
# EXCLUDE     := $(SRCDIR)/main.c $(SRCDIR)/mlx_%.c
# SRCS        := $(filter-out $(EXCLUDE), $(SRC_ALL)) $(GNL_SRCS)

SRCS        := $(SRC_ALL) $(GNL_SRCS)

OBJS        := $(SRCS:.c=.o)

# -----------------------------------------------------------------------------#
# rules
# -----------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

# libft build
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# compile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
