CC = g++
LNG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = -I/opt/homebrew/include -I./libs
LINKER_FLAGS = -L/opt/homebrew/lib \
				-lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf\
				-llua5.4 
SOURCE_FILES = src/*.cpp src/Game/*.cpp src/ECS/*.cpp src/Logger/*.cpp
OBJ_NAME = -o gameengine

build:
	$(CC) $(COMPILER_FLAGS) $(LNG_STD) $(SOURCE_FILES) $(OBJ_NAME) $(INCLUDE_PATH) $(LINKER_FLAGS)
run:
	./gameengine
clean:
	rm gameengine