#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <typeinfo>
#include <map>

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
	default: return false; break;
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
	catch (const exception&)
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
			cout << "Invalid  input." << endl;
			cout << "Enter the  desired position as a number: " << endl;
			cin >> InputPosition;
		}
		if (stoi(InputPosition) < 1 || stoi(InputPosition) > 9)
		{
			while (stoi(InputPosition) < 1 || stoi(InputPosition) > 9)
			{
				cout << "Number  must be in range 1 - 9 !" << endl;
				cout << "Enter  the desired position as a number from the specified range: " << endl;
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
	for (int row = 0; row < sizeof(matrix) - 1; row++)
	{
		for (int column = 0; column < sizeof(row) - 1; column++)
		{
			cout << "  |  ";
			cout << matrix[row][column];                             
		}
		cout << "  |  ";
		cout << endl;
		if (row != 2)
			cout << " " << string(21, '-');     
		cout << endl;
	}
}

bool checkNamesAnswer(char answer, bool nameKeaper)
{
	switch (toupper(answer))
	{
	case 'Y':
		nameKeaper = true;
		break;
	case 'N':
		nameKeaper = false;
		break;
	default:
		nameKeaper = false;
		break;
	}
	return nameKeaper;
}


int main()
{
	bool nameKeaper = false;

	string player1, player2, names[2];
	map<string, int> scoreRecords = {};

top:

	system("cls");
	string GameResult = " ", InputPosition = " ";

	if (nameKeaper == false)
	{
		cout << "Enter a name for player1: ";
		cin >> player1;
		cout << "Enter a name for player2: ";
		cin >> player2;
		names[0] = player1;
		names[1] = player2;
		scoreRecords[player1] = 0;
		scoreRecords[player2] = 0;
	}

	char continueGameAnswer, keepNamesAnswer;
	int desiredPosition, i = 2;


	char matrix[3][3] = { { '1', '2', '3' }, {'4', '5', '6'}, {'7', '8', '9'} };  

	do
	{
		system("cls");  

		PrintMatrix(matrix);

		cout << "Enter the desired position as a number: " << endl;

		cin >> InputPosition;     

		

		desiredPosition = stoi(CheckInputValidation(InputPosition));      


		if (!CheckPosition(desiredPosition, matrix))     
		{
			while (CheckPosition(desiredPosition, matrix) == false)
			{
				cout << "Position already taken. Choose another one !" << endl;
				cin >> InputPosition;
				//CheckInputValidation(InputPosition);
				desiredPosition = stoi(CheckInputValidation(InputPosition));
			}

		}


		switch (desiredPosition)              
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
		default:break;
		}

		i += 1;


		if (         
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
			{
				if (nameKeaper == false)
				{
					scoreRecords[player1]++;
					cout << "Player " << player1 << " wins!" << "  --->  Score: ";
					cout << player1 << " " << scoreRecords[player1] << " : " << scoreRecords[player2] << " " << player2 << endl << endl;
				}

				else
				{
					scoreRecords[player1]++;
					cout << "Player " << names[0] << " wins!" << "  --->  Score: ";
					cout << player1 << " " << scoreRecords[player1] << " : " << scoreRecords[player2] << " " << player2 << endl << endl;
				}

			}

			else if (i % 2 == 0)
			{
				if (nameKeaper == false)
				{
					scoreRecords[player2]++;
					cout << "Player " << player2 << " wins!" << "  --->  Score: ";
					cout << player1 << " " << scoreRecords[player1] << " : " << scoreRecords[player2] << " " << player2 << endl << endl;
				}

				else
				{
					scoreRecords[player2]++;
					cout << "Player " << names[1] << " wins!" << "  --->  Score: ";
					cout << player1 << " " << scoreRecords[player1] << " : " << scoreRecords[player2] << " " << player2 << endl << endl;
				}

			}

			GameResult = "Finished";
		}
		else if (i == 11)   
		{
			cout << "Ties ! No winner :( " << endl;
			cout << player1 << " " << scoreRecords[player1] << " : " << scoreRecords[player2] << " " << player2 << endl;
			GameResult = "Finished";
			break;
		}
		else
			continue;

	} while (GameResult != "Finished");

	cout << "Nicely done! One more game ? Y/N " << endl;

continueGameSwitch:

	cin >> continueGameAnswer;

	switch (toupper(continueGameAnswer))
	{
	case 'Y':
		cout << "Keep the names from previous game? Y/N" << endl;
		cin >> keepNamesAnswer;
		nameKeaper = checkNamesAnswer(keepNamesAnswer, nameKeaper);
		goto top;
		break;
	case 'N':
		system("cls");
		cout << "The score is " << player1 << " " << scoreRecords[player1] << " : " << scoreRecords[player2] << " " << player2 << endl << endl;
		cout << "Thank you for playing! Goodbye." << endl;
		break;
	default:
		system("cls");
		cout << "Please choose either Y (Yes) or N (No) !" << endl;
		goto continueGameSwitch;
		break;
	}
}

