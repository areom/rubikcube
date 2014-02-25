UNAME := $(shell uname)

MacGLFramework = -framework OpenGL -framework GLUT
LinuxGLFramework = -lglut -lGLU
GLFramework = N/A

CC = clang++
FLAG = -std=c++11 -Wno-deprecated -o
INCLUDE = -I/usr/include/GL -I/usr/include
SRC = src/*.cc

EXE = RubixCube

ifeq ($(UNAME), Linux)
	GLFramework = $(LinuxGLFramework)
endif
ifeq ($(UNAME), Darwin)
	GLFramework = $(MacGLFramework)
endif

all: run

run: 
	$(CC) $(FLAG) $(EXE) $(INCLUDE) $(SRC) $(GLFramework)
	#clang++ -std=c++11 -stdlib=libc++ -framework GLUT -framework OpenGL -Wno-deprecated rubix_cube.o main.o -o rubik

clean:
	rm *.o *.out
