all: run

run:
	clang++ -std=c++11 -stdlib=libc++ -framework GLUT -framework OpenGL -Wno-deprecated -o rubik.out src/main.cc

clean:
	rm *.o *.out
