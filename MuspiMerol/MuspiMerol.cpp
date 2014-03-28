#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// Exit status constants
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

const string opener = "Muspi Merol ";
const int upper = -32;
const char* alpha = "abcdefghijklmnopqrstuvwxyz";

string generateWord(bool sentenceFirst)
{
	int minWordLength = 1;
	int maxWordLength = 10;
	string word = "";

	int wordLength = rand() % maxWordLength + minWordLength;
	for (int i = 0; i < wordLength; i++)
	{
		word += (alpha[rand() % 25]);
	}

	if (sentenceFirst)
	{
		word[0] = (char)word[0] + upper;
	}

	return word;
}

string generateSentence()
{
	int minWords = 3;
	int maxWords = 14;
	string sentence = "";

	int words = rand() % (maxWords - minWords) + minWords;
	for (int i = 0; i < words; i++)
	{
		if (i == 0)
			sentence += generateWord(true);
		else
			sentence += " " + generateWord(false);
	}

	// Finish sentence with period
	sentence += ". ";

	return sentence;
}

string generateParagraph()
{
	int minSentences = 3;
	int maxSentences = 6;
	string paragraph = "";

	return paragraph;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "MuspiMerol takes 1 argument, which is the number of paragraphs to generate." << endl;
		cout << "Usage - ./muspimerol.o # (# being the number of paragraphs)" << endl;
		return EXIT_FAILURE;
	}

	// Seed random generator with time based seed
	srand(time(NULL));

	string muspiMerol = opener;
	muspiMerol += generateSentence();

	cout << muspiMerol << endl;

	cin.get();
	return EXIT_SUCCESS;
}