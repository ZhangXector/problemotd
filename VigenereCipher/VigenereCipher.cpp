#include <iostream>
#include <string.h>
#include <string>

using namespace std;

// Exit status constants
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Alphabet string constant
const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char encrypt_char(char k, char m)
{
	int kNum = alpha.find_first_of(k);
	int mNum = alpha.find_first_of(m);
	int newNum = kNum + mNum;
	newNum %= alpha.size();
	return alpha[newNum];
}

string encrypt(string key, string message)
{
	string returnString;
	for(int i = 0, j = 0; i < message.size(); ++i, ++j)
	{
		if(j >= key.size())
			j = 0;
		returnString += encrypt_char(key[j], message[i]);
	}
	return returnString;
}

int main(int argc, char* argv[])
{
	// Check if this is an encode or decode
	string arg1(argv[1]);
	if(arg1 == "-e")
	{
		// Wrong amount of arguments for encoding
		if(argc != 4)
		{
			cout << "When encoding please supply a command, key, and message.\n";
			cout << "(e.g. vigenere-cipher.o -e key message)\n";
			cin.get();
			return EXIT_FAILURE;
		}
		else
		{
			// Check to make sure the key is shorter than the message being encrypted
			if(strlen(argv[2]) > strlen(argv[3]))
			{
				cout << "Key must me shorter than the message.\n";
				cin.get();
				return EXIT_FAILURE;
			}
			else
			{
				string key(argv[2]);
				string message(argv[3]);
				cout << encrypt(key, message) << "\n";
			}
		}
	}
	else if(arg1 == "-d")
	{
		if(argc != 3)
		{
			cout << "When decoding please supply a command and message.\n";
			cout << "(e.g. vigenere-cipher.o -d message)\n";
			cin.get();
			return EXIT_FAILURE;
		}
		else
		{
			string message(argv[2]);
			//cout << decrypt(message) << "\n";
		}
	}
	else
	{
		cout << "Please supply a command. Use -e for encode and -d for decode.\n";
		cout << "(e.g. vigenere-cipher.o -(e/d) <key> message)\n";
		cout << "You entered -> " << argv[1] << "\n";
		cin.get();
		return EXIT_FAILURE;
	}


	// New line, because aesthetics
	cout << "\n";

	// Wait for user input before closing window
	cin.get();

	// Successfully exit
	return EXIT_SUCCESS;
}
