#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Build Matrix Function
// Creates a matrix of given size
// and fills with sequential integers
// Params: Size of the matrix
// Returns: 2D vector matrix
vector< vector<int> > buildMatrix(int matrixSize)
{
	// Initialize 2-dimensional vector matrix
	vector< vector<int> > matrix(matrixSize, vector<int>(matrixSize));

	// Value to add to a cell in the matrix
	int value = 1;

	// Loops through width and height of matrix
	// adds values and increments value
	for(int i = 0; i < matrixSize; ++i)
	{
		for(int j = 0; j < matrixSize; ++j)
		{
			matrix[i][j] = value;
			value++;
		}
	}

	// return matrix
	return matrix;
}

// Rotate Counter-Clockwise Function
// Rotates a matrix counter-clockwise
// Params: The matrix to be rotated
// Returns: The rotated matrix
vector< vector<int> > rotateCounterClockwise(vector< vector<int> >& matrix)
{
	vector< vector<int> > copyMatrix = matrix;

	int row = 0;
	int column = matrix.size() - 1;

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			matrix[i][j] = copyMatrix[row][column];
			if (row < matrix.size() - 1)
				++row;
			else
				row = 0;
		}
		--column;
	}

	return matrix;
}

// Rotate Clockwise Function
// Rotates a matrix clockwise
// Params: The matrix to be rotated
// Returns: The rotated matrix
vector< vector<int> > rotateClockwise(vector< vector<int> >& matrix)
{
	vector< vector<int> > copyMatrix = matrix;

	int row = matrix.size() - 1;
	int column = 0;

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			matrix[i][j] = copyMatrix[row][column];
			if (row > 0)
				--row;
			else
				row = matrix.size() - 1;
		}
		++column;
	}

	return matrix;
}

// Print Matrix Function
// Prints all values of the matrix
// Params: The matrix to print
void printMatrix(vector< vector<int> >& matrix)
{
	for(int i = 0; i < matrix.size(); ++i)
	{
		cout << "\n";
		for(int j = 0; j < matrix.size(); ++j)
		{
			cout<<matrix[i][j] << "\t";
		}
	}

	cout << "\n";
}

// Main Function
// Takes an argument for matrix size
// creates a matrix and rotates it clockwise
// and counter-clockwise
int main(int argc, char* argv[])
{
	int matrixSize;
	
	// Get size of matrix from command line arguments
	if(argc == 1)
	{
		// Default 5
		matrixSize = 5;
	}
	else if(argc == 2)
	{
		// Parse string to int value for passed in size
		stringstream convert(argv[1]);
		if(!(convert >> matrixSize))
		{
			cout<<"Unable to use number " << argv[1] << ". Please use a valid number\n";
			return EXIT_FAILURE;
		}
	}
	// Error if more than 1 argument
	else
	{
		cout<<"Too many arguments. Please use matrix_rotation <size>.\n";
		return EXIT_FAILURE;
	}

	// Output matrix size
	cout << "Matrix size -> " << matrixSize << "\n\n";

	// Build matrix
	vector< vector<int> > matrix = buildMatrix(matrixSize);

	// Print matrix
	cout << "Original Matrix:\n";
	printMatrix(matrix);

	// Make a copy of the matrix
	vector< vector<int> > copyMatrix = matrix;

	// Rotate matrix clockwise
	matrix = rotateClockwise(matrix);

	// Print matrix
	cout << "Clockwise Rotated Matrix: \n";
	printMatrix(matrix);

	// Rotate matrix counter-clockwise
	matrix = copyMatrix;
	matrix = rotateCounterClockwise(matrix);

	// Print matrix
	cout << "Counter-clockwise Rotated Matrix: \n";
	printMatrix(matrix);

	// New line, because aesthetics
	cout << "\n";

	// Wait for user input before closing window
	cin.get();

	// Successfully exit
	return EXIT_SUCCESS;
}
