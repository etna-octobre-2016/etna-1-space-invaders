# Shell commands variables
# -----------------------------------------------
CC = gcc
CFLAGS = -W -Wall -Werror -std=c89
NAME = SpaceInvaders
RM = rm -f
SDLBIN = ./libs/sdl2-image/SDL2_image \
	./libs/sdl2-ttf/SDL2_ttf

# Default rule
all: clean $(NAME)

# Compiling
$(NAME):
	$(CC) $(CFLAGS) src/*.c $(SDLBIN) -o $(NAME)

# Object files removing
clean:
	$(RM) $(NAME)

# Installs dependencies
install: sdl-install

# Installs SDL lib
sdl-install: sdl-build sdl-copy

# Builds SDL lib
sdl-build:
	cd vendors/sdl && ./configure && make && echo "SDL build completed."

# Creates symbolik links in libs/sdl2
sdl-copy:
	mkdir -p libs/sdl2/headers
