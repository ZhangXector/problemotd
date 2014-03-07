all: matrix-rotation

run: release
	./matrix-rotation

debug: clean matrix-rotation-debug
	gdb matrix-rotation

release: clean matrix-rotation

matrix-rotation-debug: MatrixRotation.cpp
	g++ MatrixRotation.cpp -g -o matrix-rotation

matrix-rotation: MatrixRotation.cpp
	g++ MatrixRotation.cpp -o matrix-rotation

clean:
	rm -f matrix-rotation
