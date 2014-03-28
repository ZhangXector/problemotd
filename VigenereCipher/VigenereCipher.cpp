#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

// Exit status constants
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Alphabet string constant
const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Encrypt Character Function
// Encrypt a character from message with corresponding key character
// Params: Key character, message character
// Returns: Encrypted character
char encrypt_char(char k, char m)
{
	// Get character numbers
	int kNum = alpha.find_first_of(k);
	int mNum = alpha.find_first_of(m);

	// Add numbers
	int newNum = kNum + mNum;
	
	// Mod by alpha size
	newNum %= alpha.size();

	// Return encrypted character
	return alpha[newNum];
}

// Decrypt Character Function
// Decrypt a character from message with corresponding key character
// Params: Key character, message character
// Returns: Decrypted character
char decrypt_char(char k, char m)
{
	// Get character numbers
	int kNum = alpha.find_first_of(k);
	int mNum = alpha.find_first_of(m);

	// Add length of alphabet if message character is smaller than key character
	if(mNum < kNum)
	{
		mNum += 26;
	}

	// Subtract numbers
	int newNum = mNum - kNum;

	// Return decrypted character
	return alpha[newNum];
}

// Encryption Function
// Encrypts/Decrypts a message with a key
// Params: Bool encrypt/decrypt, key string, message string
// Returns: Encrypted/Decrypted string
string encryption(bool encrypt, string key, string message)
{
	// Initialize string
	string returnString;

	// Encrypt or decrypt all message characters with key character
	for(int i = 0, j = 0; i < message.size(); ++i, ++j)
	{
		// Wraps key number value around to beginning
		if(j >= key.size())
			j = 0;
		
		if(encrypt)
		{
			// Add encrypted character to string
			returnString += encrypt_char(key[j], message[i]);
		}
		else
		{
			// Add decrypted character to string
			returnString += decrypt_char(key[j], message[i]);
		}
	}

	// Return encrypted string
	return returnString;
}

int main(int argc, char* argv[])
{
	// Check if this is an encode or decode
	string arg1(argv[1]);

	// Check for correct number of arguments
	if(argc != 4)
	{
		cout << "When encoding please supply a command, key, and message.\n";
		cout << "(e.g. vigenere-cipher.o -e key message)\n";
		cin.get();
		return EXIT_FAILURE;
	}
	
	// Check to make sure the key is shorter than the message being encrypted
	if(strlen(argv[2]) > strlen(argv[3]))
	{
		cout << "Key must me shorter than the message.\n";
		cin.get();
		return EXIT_FAILURE;
	}
	
	// Encode?
	if(arg1 == "-e")
	{
		// Get string values for key and message and convert to uppercase
		string key(argv[2]);
		transform(key.begin(), key.end(), key.begin(), ::toupper);
		string message(argv[3]);
		transform(message.begin(), message.end(), message.begin(), ::toupper);
		// Print
		cout << encryption(true, key, message) << "\n";
	}

	// Decode?
	else if(arg1 == "-d")
	{
		// Get string values for message and convert to uppercase
		string key(argv[2]);
		transform(key.begin(), key.end(), key.begin(), ::toupper);
		string message(argv[3]);
		transform(message.begin(), message.end(), message.begin(), ::toupper);
		// Print
		cout << encryption(false, key, message) << "\n";
	}

	// Not a valid argument
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
