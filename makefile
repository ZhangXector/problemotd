all: matrix-rotation

run: release
	./matrix-rotation.o

debug: clean matrix-rotation-debug
	gdb matrix-rotation.o

release: clean matrix-rotation

matrix-rotation-debug: MatrixRotation.cpp
	g++ MatrixRotation.cpp -g -o matrix-rotation.o

matrix-rotation: MatrixRotation.cpp
	g++ MatrixRotation.cpp -o matrix-rotation.o

clean:
	rm -f matrix-rotation.o
