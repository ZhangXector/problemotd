#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char* argv[])
{
	int matrixSize;
	
	if(argc == 1)
	{
		matrixSize = 5;
	}
	else if(argc == 2)
	{
		stringstream convert(argv[1]);
		if(!(convert >> matrixSize))
		{
			cout<<"Unable to use number "<<argv[1]<<". Please use a valid number\n";
			return EXIT_FAILURE;
		}
	}
	else
	{
		cout<<"Too many arguments. Please use matrix_rotation <size>.\n";
		return EXIT_FAILURE;
	}

	cout<<"Matrix size -> "<<matrixSize;
	vector< vector<int> > matrix;

	/*
	int i, j;

	for(i = 0; i < matrixSize; ++i)
	{
		cout<<"\n";
		for (j = 0; j < matrixSize; ++j)
		{
			cout<<matrix[i][j]<<"\t";
		}
	}
	*/

	return EXIT_SUCCESS;
}
