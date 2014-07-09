# Shell commands variables
# -----------------------------------------------
CC = gcc
CFLAGS = -W -Wall -Werror -std=c89
NAME = SpaceInvaders
RM = rm -f
SDLBIN = ~/Library/Frameworks/SDL2.framework/SDL2 ~/Library/Frameworks/SDL2_image.framework/SDL2_image

# Default rule
all: clean $(NAME)

# Compiling
$(NAME):
	$(CC) $(CFLAGS) src/*.c $(SDLBIN) -o $(NAME)

# Object files removing
clean:
	$(RM) $(NAME)
