all: vigenere-cipher

run: release
	./vigenere-cipher.o

debug: clean vigenere-cipher-debug
	gdb vigenere-cipher.o

release: clean vigenere-cipher

vigenere-cipher-debug: VigenereCipher.cpp
	g++ VigenereCipher.cpp -g -o vigenere-cipher.o

vigenere-cipher: VigenereCipher.cpp
	g++ VigenereCipher.cpp -o vigenere-cipher.o

clean:
	rm -f vigenere-cipher.o
