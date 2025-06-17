########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################

AUTHOR				=	maximart && elagouch
NAME				=	cub3d
NAME_BONUS			=	cub3d_bonus
HEADER				=	$(INC_DIR)cub3d.h
CC 					= 	cc
CFLAGS 				= 	-Wall -Wextra -Werror
CFLAGS 				+= 	-g3 -O2
MLX_FLAGS			=	-L$(MLX_DIR) -l:libmlx_Linux.a -lXext -lX11 -lm
AR					=	ar rcs
RM					=	rm -f

include files_mandatory.mk
include files_bonus.mk
include files_extra.mk

# Env vars depending on targets
# We use filter bc ifeq here cannot account for `make fclean bonus` or `make re_bonus`
# There are SRC_F_*CONTEXT* for things that will be inherited by this context and higher ones, and
# SRC_F_ONLY_*CONTEXT*
## Bonus
ifneq ($(filter bonus re_bonus,$(MAKECMDGOALS)),)
	SRC_F = $(SRC_F_MANDATORY) $(SRC_F_BONUS) $(SRC_F_ONLY_BONUS)
	CFLAGS += -DBONUS=1
	TARGET_NAME = $(NAME_BONUS)
	BUILD_TYPE = BONUS
## Extra
else ifneq ($(filter extra re_extra,$(MAKECMDGOALS)),)
	SRC_F = $(SRC_F_MANDATORY) $(SRC_F_BONUS) $(SRC_F_EXTRA)
	CFLAGS += -DBONUS=1 -DEXTRA=1
	TARGET_NAME = $(NAME)_extra
	BUILD_TYPE = EXTRA
## Mandatory
else
	SRC_F = $(SRC_F_MANDATORY) $(SRC_F_ONLY_MANDATORY)
	TARGET_NAME = $(NAME)
	BUILD_TYPE = MANDATORY
endif

SRC					=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_F)))
OBJ 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_F)))

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

SRC_DIR				=	src/
OBJ_DIR				=	obj/
INC_DIR				=	include/

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################

LIBFT_DIR			=	libft/
LIBFT				=	$(LIBFT_DIR)libft.a

MLX_DIR				=	minilibx-linux/
MLX					=	$(MLX_DIR)libmlx_Linux.a

########################################################################################################################
#                                                       TARGETS                                                        #
########################################################################################################################

all:					.print_header $(LIBFT) $(MLX) $(TARGET_NAME)

bonus:					.print_header $(LIBFT) $(MLX) $(TARGET_NAME)

extra:					.print_header $(LIBFT) $(MLX) $(TARGET_NAME)

clean:					.print_header
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(OBJ_DIR)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@rm -rf $(OBJ_DIR)
							@printf "$(RED)=> Deleted!$(DEF_COLOR)\n"
							@printf "\n"
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(LIBFT_DIR)$(OBJ_DIR)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@$(MAKE) --silent -C $(LIBFT_DIR) clean
							@printf "$(RED)=> Deleted!\n$(DEF_COLOR)"
							$(call SEPARATOR)

fclean: 				clean
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(NAME)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@$(RM) $(NAME) $(NAME_BONUS) $(NAME)_extra
							@printf "$(RED)=> Deleted!$(DEF_COLOR)\n"
							@printf "\n"
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(LIBFT)]:"  "$(GREEN)[✓]$(DEF_COLOR)\n"
							@$(MAKE) --silent -C $(LIBFT_DIR) fclean
							@printf "$(RED)=> Deleted!$(DEF_COLOR)\n"
							@printf "\n"
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(MLX_DIR)$(OBJ_DIR)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@$(MAKE) --silent -C $(MLX_DIR) clean
							@printf "$(RED)=> Deleted!\n$(DEF_COLOR)\n"
							$(call SEPARATOR)

re: 					fclean all

re_bonus:				fclean bonus

re_extra:				fclean extra

.print_header:
							$(call DISPLAY_TITLE)
							$(call SEPARATOR)
							$(call BUILD)
							$(call SEPARATOR)

.PHONY: 				all bonus extra clean fclean re re_bonus re_extra norm

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(TARGET_NAME):			$(LIBFT) $(MLX) $(OBJ)
							@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $@

$(LIBFT):
							@$(MAKE) --silent -C $(LIBFT_DIR)

$(MLX):
							@$(MAKE) --silent -C $(MLX_DIR)

$(OBJ_DIR)%.o: 			$(SRC_DIR)%.c $(HEADER)
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)$(INC_DIR) -I$(MLX_DIR) -c $< -o $@
							$(call PROGRESS_BAR_PERCENTAGE)
							$(if $(filter $(COMPILED_SRCS),$(SRCS_TO_COMPILE)),$(call SEPARATOR))

########################################################################################################################
#                                                       COLOURS                                                        #
########################################################################################################################

DEF_COLOR			=	\033[0;39m
ORANGE				=	\033[0;33m
GRAY				=	\033[0;90m
RED					=	\033[0;91m
GREEN				=	\033[1;92m
YELLOW				=	\033[1;93m
BLUE				=	\033[0;94m
MAGENTA				=	\033[0;95m
CYAN				=	\033[0;96m
WHITE				=	\033[0;97m

########################################################################################################################
#                                                       DISPLAY                                                        #
########################################################################################################################

SPACEMENT			=	-41
COMPILED_SRCS		=	0
FRAMES				=	⠋ ⠙ ⠹ ⠸ ⠼ ⠴ ⠦ ⠧ ⠇ ⠏
SLEEP_FRAME			=	0.001

SRCS_TO_COMPILE		=	$(shell find $(SRC_DIR) -type f -name "*.c" -newer $(NAME) 2>/dev/null | wc -l)
ifeq ($(SRCS_TO_COMPILE),0)
	SRCS_TO_COMPILE =	$(words $(SRC_F))
endif

define PROGRESS_BAR_PERCENTAGE
						$(eval COMPILED_SRCS := $(shell expr $(COMPILED_SRCS) + 1))
						@if [ $(COMPILED_SRCS) -eq 1 ]; then \
							printf "$(BLUE)[$(NAME)]:$(DEF_COLOR)\n"; \
						fi
						@percentage=$$(if [ $(SRCS_TO_COMPILE) -eq 0 ]; then echo 0; else echo "scale=0; $(COMPILED_SRCS) * 100 / $(SRCS_TO_COMPILE)" | bc; fi); \
						for frame in $(FRAMES); do \
							printf "\r$$frame Compiling... [%d/%d] %d%%" $(COMPILED_SRCS) $(SRCS_TO_COMPILE) $$percentage; \
							sleep $(SLEEP_FRAME); \
						done; \
						if [ $(COMPILED_SRCS) -eq $(SRCS_TO_COMPILE) ]; then \
							printf "%-42b%b" "\r$(GREEN)Compilation finished [$(COMPILED_SRCS)/$(SRCS_TO_COMPILE)]" "$(GREEN)[✓]$(DEF_COLOR)\n"; \
						fi
endef

#TITLE ASCII ART - SLANT
define	DISPLAY_TITLE
						@echo "$(RED)		   ______      __        _____ ____ "
						@echo "$(ORANGE)		  / ____/_  __/ /_  ___ |__  // __ \\"
						@echo "$(YELLOW)		 / /   / / / / __ \\/ _ \\ /_ </ / / /"
						@echo "$(GREEN)		/ /___/ /_/ / /_/ /  __/__/ / /_/ / "
						@echo "$(BLUE)		\____/\\__,_/_.___/\\___/____/_____/  "
						@echo "$(PURPLE)  		                                  $(DEF_COLOR)"
						@printf "\n"
endef

define	SEPARATOR
						@printf "\n"
						@echo "$(ORANGE)--------------------------------------------------------------------------$(DEF_COLOR)";
						@printf "\n"
endef

define	BUILD
						@printf "%-47b%b" "$(GREEN)AUTHOR:$(DEF_COLOR)" "$(AUTHOR)\n";
						@printf "%-47b%b" "$(GREEN)NAME:$(DEF_COLOR)" "$(NAME)\n";
						@printf "%-47b%b" "$(GREEN)CC:$(DEF_COLOR)" "$(CC)\n";
						@printf "%-47b%b" "$(GREEN)FLAGS:$(DEF_COLOR)" "$(CFLAGS)\n";
endef

norm:
	@norminette src libft include|grep Error