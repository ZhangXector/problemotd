all: release

encode: release
	./vigenere-cipher.o -e REDDIT TODAYISMYBIRTHDAY

decode: release
	./vigenere-cipher.o -d ZEJFOKHTMSRMELCPODWHCGAW

debug-encode: clean vigenere-cipher-debug
	gdb vigenere-cipher.o -e REDDIT TODAYISMYBIRTHDAY

debug-decode: clean vigenere-cipher-debug
	gdb vigenere-cipher.o -d ZEJFOKHTMSRMELCPODWHCGAW

release: clean vigenere-cipher

vigenere-cipher-debug: VigenereCipher.cpp
	g++ VigenereCipher.cpp -g -o vigenere-cipher.o

vigenere-cipher: VigenereCipher.cpp
	g++ VigenereCipher.cpp -o vigenere-cipher.o

clean:
	rm -f vigenere-cipher.o
