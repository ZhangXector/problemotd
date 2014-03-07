all: matrix-rotation

run: release
	./matrix-rotation

debug: matrix-rotation-debug
	gdb matrix-rotation

release: clean matrix-rotation

matrix-rotation-debug: MatrixRotation.c
	gcc MatrixRotation.c -g -o matrix-rotation

matrix-rotation: MatrixRotation.c
	gcc MatrixRotation.c -o matrix-rotation

clean:
	rm -f matrix-rotation
