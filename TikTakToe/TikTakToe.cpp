#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <typeinfo>

using namespace std;


bool CheckPosition(int position, char matrix[3][3])
{
	switch (position)
	{
	case 1:
		if (matrix[0][0] == 'X' || matrix[0][0] == 'O') return false;
		else if (matrix[0][0] = 1) return true;
		break;
	case 2:
		if (matrix[0][1] == 'X' || matrix[0][1] == 'O') return false;
		else if (matrix[0][1] == 2) return true;
		break;
	case 3:
		if (matrix[0][2] == 'X' || matrix[0][2] == 'O') return false;
		else if (matrix[0][2] == 3) return true;
		break;
	case 4:
		if (matrix[1][0] == 'X' || matrix[1][0] == 'O');
		else if (matrix[1][0] == 4) return true;
		break;
	case 5:
		if (matrix[1][1] == 'X' || matrix[1][1] == 'O') return false;
		else if (matrix[1][1] == 5) return true;
		break;
	case 6:
		if (matrix[1][2] == 'X' || matrix[1][2] == 'O') return false;
		else if (matrix[1][2] == 6) return true;
		break;
	case 7:
		if (matrix[2][0] == 'X' || matrix[2][0] == 'O') return true;
		else if (matrix[2][0] == 7) return true;
		break;
	case 8:
		if (matrix[2][1] == 'X' || matrix[2][1] == 'O') return false;
		else if (matrix[2][1] == 8) return true;
		break;
	case 9:
		if (matrix[2][2] == 'X' || matrix[2][2] == 'O') return false;
		else if (matrix[2][2] == 9) return true;
		break;
	}

}

bool TryParseInput(string value)
{
	try
	{
		int ParsedNum = stoi(value);
		if (typeid(ParsedNum).name() == typeid(int).name())
		{
			return true;
		}
		return false;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return false;
}

string CheckInputValidation(string InputPosition)
{
	if (TryParseInput(InputPosition) != true)
	{
		while (TryParseInput(InputPosition) == false)
		{
			cout << "Invalid input." << endl;
			cout << "Enter the desired position as a number: " << endl;
			cin >> InputPosition;
		}
		if (stoi(InputPosition) < 1 || stoi(InputPosition) > 9)
		{
			while (stoi(InputPosition) < 1 || stoi(InputPosition) > 9)
			{
				cout << "Number must be in range 1 - 9 !" << endl;
				cout << "Enter the desired position as a number from the specified range: " << endl;
				cin >> InputPosition;
			}
		}
	}
	else if (TryParseInput(InputPosition) == true)
	{
		if (stoi(InputPosition) < 1 || stoi(InputPosition) > 9)
		{
			while (stoi(InputPosition) < 1 || stoi(InputPosition) > 9)
			{
				cout << "Number must be in range 1 - 9 !" << endl;
				cout << "Enter the desired position as a number from the specified range: " << endl;
				cin >> InputPosition;
			}
		}
	}

	return InputPosition;
}

void PrintMatrix(char matrix[3][3])
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			cout << "  |  ";
			cout << matrix[row][column];                             //print matrix
		}
		cout << "  |  ";
		cout << endl;
		if (row != 2)
			cout << " " << string(21, '-');
		cout << endl;
	}
}



int main()
{
	top:
	system("cls");

	string player1;
	cout << "Enter a name for player1: " << endl;
	cin >> player1;
	string player2;
	cout << "Enter a name for player2: " << endl;
	cin >> player2;

	string names[2] = {player1, player2};

	string GameResult = "";
	string InputPosition = " ";

	char answer;
	int desiredPosition;
	int i = 2;

	char matrix[3][3] = { { '1', '2', '3' }, {'4', '5', '6'}, {'7', '8', '9'} };  // creating a matrix with 3x3 rows/columns

	do
	{
		system("cls");  // clear everything on console

		PrintMatrix(matrix);

		cout << "Enter the desired position as a number: " << endl;

		cin >> InputPosition;

		CheckInputValidation(InputPosition);

		desiredPosition = stoi(InputPosition);

		if (!CheckPosition(desiredPosition, matrix))     // check if position is allready taken by boolean
		{
			while (CheckPosition(desiredPosition, matrix) == false)
			{
				cout << "Position allready taken. Choose nother one !" << endl;
				cin >> InputPosition;
				CheckInputValidation(InputPosition);
				desiredPosition = stoi(InputPosition);
			}
			
		}

		if (desiredPosition >= 1 && desiredPosition <= 9)
		{

			switch (desiredPosition)              // selecting the desired position 
			{
			case 1: if (i % 2 == 0) matrix[0][0] = 'X'; else matrix[0][0] = 'O'; break;
			case 2: if (i % 2 == 0) matrix[0][1] = 'X'; else matrix[0][1] = 'O'; break;
			case 3: if (i % 2 == 0) matrix[0][2] = 'X'; else matrix[0][2] = 'O'; break;
			case 4: if (i % 2 == 0) matrix[1][0] = 'X'; else matrix[1][0] = 'O'; break;
			case 5: if (i % 2 == 0) matrix[1][1] = 'X'; else matrix[1][1] = 'O'; break;
			case 6: if (i % 2 == 0) matrix[1][2] = 'X'; else matrix[1][2] = 'O'; break;
			case 7: if (i % 2 == 0) matrix[2][0] = 'X'; else matrix[2][0] = 'O'; break;
			case 8: if (i % 2 == 0) matrix[2][1] = 'X'; else matrix[2][1] = 'O'; break;
			case 9: if (i % 2 == 0) matrix[2][2] = 'X'; else matrix[2][2] = 'O'; break;
			}

			i += 1;
		}

		if (         // check for winner
			matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2] ||
			matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0] ||
			matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] ||
			matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] ||
			matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2] ||
			matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2] ||
			matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2] ||
			matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1]
			)
		{
			system("cls");
			
			PrintMatrix(matrix);

			if (i % 2 == 1)
				cout << "Player " << player1 << " wins!" << endl;
			else if (i % 2 == 0)
				cout << "Player " << player2 << " wins!" << endl;
			GameResult = "Finished";
		}
		else if (i == 11)   // check for ties
		{
			cout << "Ties ! No winner :( " << endl;
			GameResult = "Finished";
			break;
		}
		else
			continue;
	} while (GameResult != "Finished");

	cout << "Nicely done! One more game ? Y/N " << endl;

	cin >> answer;

	switch (toupper(answer))
	{
	case 'Y': goto top; break;
	case 'N': cout << "Thank you for playing! Goodbye." << endl; break;
	default: break;
	}
}

