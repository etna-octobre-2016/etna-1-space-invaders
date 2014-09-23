# Shell commands variables
# -----------------------------------------------
CC = gcc
CFLAGS = -W -Wall -Werror -std=c89
NAME = SpaceInvaders
WORKSPACE = /Users/ahemt_s/Documents/etna/projets/spaceinvader/demo
LIBS = $(WORKSPACE)/libs
LSDL = $(LIBS)/sdl2
LSDL_IMAGE = $(LIBS)/sdl2-image
LSDL_TTF = $(LIBS)/sdl2-ttf
RM = rm -f

# Default rule
all: clean $(NAME)

# Compiling
$(NAME):
	$(CC) $(CFLAGS) -I$(LSDL)/include/SDL2 -L$(LSDL)/lib -lSDL2 src/*.c -o $(NAME)

# Object files removing
clean:
	$(RM) $(NAME)

# Installs dependencies
install: install-sdl install-sdl-image install-sdl-ttf

# Installs SDL lib
install-sdl:
	mkdir -p $(LSDL) && cd vendors/sdl2 && ./configure --prefix=$(LSDL) && make && make install && ln -s $(LSDL)/bin/sdl2-config /usr/local/bin && echo "SDL build completed." && cd ../../

install-sdl-image:
	mkdir -p $(LSDL_IMAGE) && cd vendors/sdl2-image && ./configure --prefix=$(LSDL_IMAGE) && make && make install && echo "SDL_image build completed." && cd ../../

install-sdl-ttf:
	mkdir -p $(LSDL_TTF) && cd vendors/sdl2-ttf && ./configure --prefix=$(LSDL_TTF) && make && make install && echo "SDL_ttf build completed." && cd ../../