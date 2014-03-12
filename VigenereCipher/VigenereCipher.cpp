#include <iostream>
#include <string.h>

using namespace std;

// Exit status constants
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Alphabet string constant
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, char* argv[])
{
	// Check to make sure we have a key and message
	if(argc != 3)
	{
		cout << "Please use this program with a key and messsage.\n(e.g. vigenere-cipher.o reddit todayismybirthday)\n";
		return EXIT_FAILURE;
	}

	// Check to make sure the key is shorter than the message being encrypted
	if(strlen(argv[1]) > strlen(argv[2]))
	{
		cout << "Key must me shorter than the message.\n";
		return EXIT_FAILURE;
	}

	// Store key and message in strings
	string key(argv[1]);
	string message(argv[2]);

	for(int i = 0, j = 0; i < message.size(); ++i, ++j)
	{
		if(j >= key.size())
			j = 0;

	}
	/*
	for(int i = 0; i < key.size(); ++i)
	{
		cout << "\nKey: " << key[i] << " -> \t" << alpha.find_first_of(key[i]) << "\n\t\t+\nMessage: " << message[i] << " -> \t" << alpha.find_first_of(message[i]);
	}
	*/

	cout << "\n\nKey: " << key << "\n";
	cout << "Message: " << message << "\n";

	// New line, because aesthetics
	cout << "\n";

	// Wait for user input before closing window
	cin.get();

	// Successfully exit
	return EXIT_SUCCESS;
}
