/*
-----------------------------------------

	* Course: The Complete C++ Developer Course - John P. Baugh
	* Author: Noah Louvet
	* Section: 5 - Functions

-----------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initialzeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);



bool whoPlaying = 1; // 1 = X
string winner = "";
//string gameBoard[ROWS][COLS];

int main()
{
	
	runGame();

	return 0;
}





void runGame()
{

	//string winner = "";
	//bool whoPlaying = true;
	string gameBoard[ROWS][COLS]; 
	initialzeGameBoard(gameBoard);
	printCurrentBoard(gameBoard);

	while (winner == "")
	{
		
		getUserInput(whoPlaying, gameBoard);
		getWinner(gameBoard);
	}

	cout << "the winner is : " << winner << endl;
	cout << "Thank you for playing! " << endl << endl;
}


void initialzeGameBoard(string gameBoard[ROWS][COLS])
{
	//Loops through the game board and ensures all elements are set to a space

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gameBoard[i][j] = " ";
		}
	}
}


void printCurrentBoard(string gameBoard[ROWS][COLS])
{
	//Takes the current board, prints the lines and the game board as necessary
	cout << endl << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (j < 2)
			{
				cout << gameBoard[i][j] << " | ";
			}
			else
			{
				cout << gameBoard[i][j];
			}
			
		}

		if (i != 2)
		{
			cout << endl;
			cout << "- - - - -" << endl;
		}
	}

	cout << endl;
}


void getUserInput(bool xTurn, string gameBoard[ROWS][COLS])
{
	//takes a parameter representing whose turn it is, and the game board

	//Goes into a loop to determine if the input has been valid yet or not
	//o Valid selections include values for rows and cols >= 0, and <= 2
		//o Then, I use the function cellAlreadyOccupied to determine if we keep asking or
		//consider the selected row and column to be legitimate or not
		//o After the validation loop, I then put an X or an O inside the gameboard at the
		//row or the column

	cout << endl << endl;

	int row, col;

	if (xTurn == 1)
	{
		cout << "it is X's turn" << endl;
		whoPlaying = 0;
	}
	else if (xTurn == 0)
	{
		cout << "it is O's turn" << endl;
		whoPlaying = 1;
	}



	cout << "Please enter the row THEN the column, each from 0, 1 or 2, seperated by a space" << endl;
	cin >> row >> col;


	if (row >= 0 && row <= 2 && col >= 0 && col <= 2)
	{
		while(cellAlreadyOccupied(row, col, gameBoard) == true)
		{ 
			if (row >= 0 && row <= 2 && col >= 0 && col <= 2) {
				cout << "that cell is already occupied" << endl << endl;
				cout << "Please enter the row THEN the column, each from 0, 1 or 2, seperated by a space" << endl;
				cin >> row >> col;
			}
			else
			{
				cout << "invalid input, out of range!" << endl << endl;
				cout << "Please enter the row THEN the column, each from 0, 1 or 2, seperated by a space" << endl;
				cin >> row >> col;
			}
		}
		
	}
	else if(xTurn == 1)
	{
		cout << "invalid input, out of range!" << endl << endl;
		getUserInput(1, gameBoard);
	}
	else if (xTurn == 0)
	{
		cout << "invalid input, out of range!" << endl << endl;
		getUserInput(0, gameBoard);
	}

	if (xTurn == 1)
	{
		gameBoard[row][col] = "X";
		printCurrentBoard(gameBoard);
	}
	else if (xTurn == 0)
	{
		gameBoard[row][col] = "O";
		printCurrentBoard(gameBoard);
	}
	
}


bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS])
{
	//returns whether the gameboard has a space at that row and column, which
	//would mean the cell is available

	bool occupiedCell;

	if (gameBoard[row][col] == " ")
	{
		occupiedCell = false;
	}
	else
	{
		occupiedCell = true;
	}

	return occupiedCell;
}


string getWinner(string gameBoard[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{


			if (gameBoard[i][0] == "X" && gameBoard[i][1] == "X" && gameBoard[i][2] == "X") // rows
			{
				winner = "X";
			}

			else if (gameBoard[i][0] == "O" && gameBoard[i][1] == "O" && gameBoard[i][2] == "O")
			{
				winner = "O";
			}


			//BETTER WAY OF DOING IT!!

			//if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
			//{
			//	winner = gameBoard[i][0];
			//}
			///////

			else if (gameBoard[0][j] == "X" && gameBoard[1][j] == "X" && gameBoard[2][j] == "X") // columns
			{
				winner = "X";
			}

			else if (gameBoard[0][j] == "O" && gameBoard[1][j] == "O" && gameBoard[2][j] == "O")
			{
				winner = "O";
			}
		}
	}

	if (gameBoard[0][0] == "X" && gameBoard[1][1] == "X" && gameBoard[2][2] == "X")
	{
		winner = "X";
	}

	else if (gameBoard[0][0] == "O" && gameBoard[1][1] == "O" && gameBoard[2][2] == "O")
	{
		winner = "O";
	}

	else if (gameBoard[0][2] == "X" && gameBoard[1][1] == "X" && gameBoard[2][0] == "X")
	{
		winner = "X";
	}

	else if (gameBoard[0][2] == "O" && gameBoard[1][1] == "O" && gameBoard[2][0] == "O")
	{
		winner = "O";
	}
	else if (isBoardFull(gameBoard) == true)
	{
		winner = "no one, it's a tie!";
	}

	return winner;
}


bool isBoardFull(string gameBoard[ROWS][COLS])
{	
	/* Loops through the game board and determines if all the cells are occupied
o Hint: there are 9 total cells. If I count nine non-spaces, then that means the
board is full
o This function is crucial for determining the “cat’s game”, that is, that there is a
tie – no winner */


	int spaceCounter = 0;
	bool isFull;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (gameBoard[i][j] == " ")
			{
				spaceCounter++;
			}
		}
	}

	if (spaceCounter != 0)
	{
		//cout << "counter: " << spaceCounter << endl;
		//cout << "is it full? ";
		isFull = false;
	}
	else
	{
		//cout << "counter: " << spaceCounter << endl;
		//cout << "is it full? ";
		isFull = true;
	}

	return isFull;
}

