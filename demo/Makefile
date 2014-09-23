# Shell commands variables
# -----------------------------------------------
CC = gcc
CFLAGS = -W -Wall -Werror -std=c89
NAME = SpaceInvaders
PROJETPATH = /Users/ahemt_s/Documents/etna/projets/spaceinvader/demo
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
sdl-install:
	mkdir -p libs/sdl2 && cd vendors/sdl && ./configure --prefix=$(PROJETPATH)/libs/sdl2 && make && make install && echo "SDL build completed." && cd ../../
