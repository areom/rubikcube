all: run

run: 
	clang++ -std=c++11 -stdlib=libc++ -Wno-deprecated -c src/rubix_cube.cc
	clang++ -std=c++11 -stdlib=libc++ -Wno-deprecated -c src/main.cc
	clang++ -std=c++11 -stdlib=libc++ -framework GLUT -framework OpenGL -Wno-deprecated rubix_cube.o main.o -o rubik

clean:
	rm *.o *.out
