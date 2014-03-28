#include <iostream>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

// Exit status constants
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Constant values
const string opener = "\tMuspi Merol ";
const int upper = -32;
const char* alpha = "abcdefghijklmnopqrstuvwxyz";

// Generate Word Function
// Generates a word with 1-10 characters
// Parameters: sentenceFirst - is the word the first in the sentence?
// Returns: Word string
string generateWord(bool sentenceFirst)
{
	// Variable declarations
	int minWordLength = 1;
	int maxWordLength = 10;
	string word = "";

	// Generate word length randomly
	int wordLength = rand() % maxWordLength + minWordLength;

	// Generate word
	for (int i = 0; i < wordLength; i++)
	{
		word += (alpha[rand() % 25]);
	}

	// Make first character of a word uppercase if first word in sentence
	if (sentenceFirst)
	{
		word[0] = (char)word[0] + upper;
	}

	return word;
}

// Generate Sentence Function
// Generates a sentence with 3-14 words
// Parameters: None
// Returns: Sentence string
string generateSentence()
{
	// Variable declaractions
	int minWords = 3;
	int maxWords = 14;
	string sentence = "";

	// Generate sentence length randomly
	int words = rand() % (maxWords - minWords) + minWords;

	// Generate sentence
	for (int i = 0; i < words; i++)
	{
		// Make first word start with capital
		if (i == 0)
			sentence += generateWord(true);
		else
			sentence += " " + generateWord(false);
	}

	// Finish sentence with period
	sentence += ". ";

	return sentence;
}

// Generate Paragraph Function
// Generates a paragraph with 3-6 sentences
// Parameters: isFirst - is this the first paragraph in the Muspi Merol?
// Returns: Paragraph string
string generateParagraph(bool isFirst)
{
	// Variable declarations
	int minSentences = 3;
	int maxSentences = 6;
	string paragraph = "";

	// Generate number of sentences randomly
	int sentences = rand() % (maxSentences - minSentences) + minSentences;

	// Generate paragraph
	for (int i = 0; i < sentences; i++)
	{
		// Make new paragraphs start with a newline and tab
		if (i == 0 && !isFirst)
			paragraph += "\n\t";
		paragraph += generateSentence();
	}

	return paragraph;
}

int main(int argc, char* argv[])
{
	// If there isn't just one argument, display error and exit
	if (argc != 2)
	{
		cout << "MuspiMerol takes 1 argument, which is the number of paragraphs to generate." << endl;
		cout << "Usage - ./muspimerol.o # (# being the number of paragraphs)" << endl;
		return EXIT_FAILURE;
	}
	
	// Get number of paragraphs from command-line argument
	int numParagraphs;
	stringstream convert((string)argv[1]);

	// If number can't be converted to int, display error and exit
	if (!(convert >> numParagraphs))
	{
		cout << "Please enter a valid number of paragraphs." << endl;
		return EXIT_FAILURE;
	}

	// Seed random generator with time based seed
	srand(time(NULL));

	// Start Muspi Merol with first two words
	string muspiMerol = opener;

	// Generate number of paragraphs user determines with argument
	for (int i = 0; i < numParagraphs; i++)
	{
		// Don't add a newline/tab if this is the first paragraph
		if (i == 0)
			muspiMerol += generateParagraph(true);
		else
			muspiMerol += generateParagraph(false);
	}

	// Output the Muspi Merol
	cout << muspiMerol << endl;

	// Wait for user input before exiting
	cin.get();
	return EXIT_SUCCESS;
}