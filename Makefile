#SRC specifies which files to compile as part of the project
SRC = *.cpp 

#INCL specifies which files to compile as part of the project
INCL = -I include/ 

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall -std=c++14

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = ludo

#This is the target that compiles our executable
all : $(SRC)
	$(CC) $(SRC) $(COMPILER_FLAGS) $(INCL) $(LINKER_FLAGS) -o $(OBJ_NAME)
