#include<iostream>
#include <windows.h>
using namespace std;
void setConsoleColor(WORD c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void check(int arr[9][9], int r, int c, int value , int ans[9][9])
{
	system("cls");
	bool check_row = true;
	for (size_t i = 0; i < 9; i++) // search in row so row is const and clumn change
	{
		if (value == arr[r - 1][i])
		{
			check_row = false;
			cout << "this number is exist in the same row !" << endl;

		}
	}
	//////////
	bool check_column = true;
	for (size_t i = 0; i < 9; i++) // search in column so it is const and row change
	{
		if (value == arr[i][c - 1])
		{
			check_column = false;
			cout << "wrong this number is exist in the same column !" << endl;

		}
	}
	//////////
	int N_r, N_c, n = 0, m = 0;
	//2 steps to determine the Net that we will check

	if (r - 1 < 3)  		//first to knew which row
		N_r = 0;
	else if (r - 1 < 6)
		N_r = 3;
	else
		N_r = 6;

	////////////////

	if (c - 1 < 3)         //second to knew which column 
		N_c = 0;
	else if (c - 1 < 6)
		N_c = 3;
	else  
		N_c = 6;
	//cout << N_r << "   "<< N_c << endl;

	for (size_t i = N_r; i < N_r + 3; i++)
	{
		for (size_t j = N_c; j < N_c + 3 ; j++)
		{
			if (value == arr[i][j])
			{
				cout << "wrong this number is exist in the Same Net";
			}
		}
		cout << endl;
	}
}
void showSudoku(int arr[9][9] , bool a[9][9])
{
	cout << "_____    _____    _____";
	cout << endl;
	for (size_t i = 0; i < 9; i++)  //show sudoku
	{
		for (size_t j = 0; j < 9; j++)
		{
			
			if (j == 3 || j == 6)
			{
				cout << "|";
			}
			
			if (arr[i][j] < 0)
				cout << " " << "|";

			else if (arr[i][j] > 0 && a[i][j] == true)
			{
				setConsoleColor(3);
				cout << arr[i][j];
				setConsoleColor(7);
				cout << "|";

			}
			else
				cout << arr[i][j] << "|";

			if (j == 2 || j == 5)
				cout << "  ";
			
		}
		cout << endl;
		if (i == 2 || i == 5)
		{
			cout << "_____    _____    _____";
			cout << endl;
		}
	}

}
void main()
{
	int arr[9][9];
	bool a[9][9] = { false };
	int ans[9][9] = { {3,8,7,4,9,1,6,2,5},{2,4,1,5,6,8,3,7,9},{5,6,9,3,2,7,4,1,8}
	,{7,5,8,6,1,9,2,3,4},{1,2,3,7,8,4,5,9,6},{4,9,6,2,5,3,1,8,7}
	,{9,3,4,1,7,6,8,5,2},{6,7,5,8,3,2,9,4,1},{8,1,2,9,4,5,7,6,3} };


	arr[0][2] = 7, arr[0][3] = 4, arr[0][4] = 9, arr[0][5] = 1, arr[0][6] = 6, arr[0][8] = 5;     //first row
	arr[1][0] = 2, arr[1][4] = 6, arr[1][6] = 3, arr[1][8] = 9; //second row
	arr[2][5] = 7, arr[2][7] = 1; //third row	
	arr[3][1] = 5, arr[3][2] = 8, arr[3][3] = 6, arr[3][8] = 4; //fourth row
	arr[4][2] = 3, arr[4][7] = 9; //fifth row
	arr[5][2] = 6, arr[5][3] = 2, arr[5][6] = 1, arr[5][7] = 8, arr[5][8] = 7; //sixth row
	arr[6][0] = 9, arr[6][2] = 4, arr[6][4] = 7, arr[6][8] = 2; // seventh row
	arr[7][0] = 6, arr[7][1] = 7, arr[7][3] = 8, arr[7][4] = 3; //eighth row
	arr[8][0] = 8, arr[8][1] = 1, arr[8][4] = 4, arr[8][5] = 5; //ninth row

	for (size_t i = 0; i < 9; i++) // to make this value const and cant be changed , i put true in a[9][9] for the correct value of arr [9][9]
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (arr[i][j] > 0)
				a[i][j] = true;
		}
	}

	showSudoku(arr,a);

	do
	{
		int r, c, value;
		bool check_const = true, check_end = true;
		cout << endl << "enter row : ";
		cin >> r;
		while (r > 9 || r < 1)
		{
			cout << "invalid , please Enter row : ";
			cin >> r;
		}

		cout << endl << "enter column : ";
		cin >> c;
		while (c > 9 || c < 1)
		{
			cout << "invalid , please Enter column : ";
			cin >> c;
		}
		cout << endl << "enter value (1-9) : ";
		cin >> value;
		while (value > 9 || value < 1)
		{
			cout << "invalid , please Enter value : ";
			cin >> value;
		}

		if (a[r - 1][c - 1] == true) //make sure user cant change constant value  
		{
			check_const = false;
			while (check_const == false)
			{
				check_const = true;
				cout << "You cant change this Number " << endl;
				cout << "Enter another coordinate " << endl;
				cout << "enter row : ";
				cin >> r;
				cout << "enter column : ";
				cin >> c;
				cout << "enter value (1-9) : ";
				cin >> value;
				if (a[r - 1][c - 1] == true)
					check_const = false;
			}

		}

		check(arr, r, c, value , ans); //check row , column and net

		arr[r - 1][c - 1] = value;       //the value will be stored whether it is correct or wrong

		showSudoku(arr, a);

		bool check_final[9][9] = { false };
		for (size_t i = 0; i < 9; i++) // check if the game is end or not 
		{
			for (size_t j = 0; j < 9; j++)
			{
				if (arr[i][j] == ans[i][j])
				{
					check_final[i][j] = true;;
				}
			}

		}
		for (size_t i = 0; i < 9; i++)
		{
			for (size_t j = 0; j < 9; j++)
			{
				if (check_final[i][j] == false)
					check_end = false;
			}
		}

		if (check_end == true)
		{
			cout << endl << endl;
			cout << "congratulations D:";
			break;    // condition to break do while when user enter all correct answer
		}
	} while (true);
}