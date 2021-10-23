#include<iostream>
#include <windows.h>
using namespace std;
void setConsoleColor(WORD c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int check(int arr[9][9])
{
	bool checkRow = true, checkColumn = true, checkNet = true;
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			for (size_t k = 1; k < 9 - j; k++)//check row
			{
				if (arr[i][j] == arr[i][k + j])
				{
					if (arr[i][j] < 0 || arr[i][k + j] < 0)
						continue;
					else
					{
						//cout << "Same row ! " << endl;
						//cout << arr[i][j] << "*****" << arr[i][k + j] << "     ";
						checkRow = false;
					}

				}
			}
			//cout << endl;
			for (size_t k = 0; k < 8 - j; k++)//check column
			{
				if (arr[j][i] == arr[k + j + 1][i])
				{
					if (arr[j][i] < 0 || arr[k + j + 1][i] < 0)
						continue;
					else
					{
						//cout << arr[j][i] << "*****" << arr[k + j + 1][i] << "      ";
						//cout << "same column ! " << endl;
						checkColumn = false;
					}

				}
			}
			//cout << endl;

		}
	}

	if (checkRow == false)
		cout << "wrong Row " << endl;
	if (checkColumn == false)
		cout << "wrong column " << endl;
	if (checkNet == false)
		cout << "wrong Net " << endl;
	if (checkRow && checkColumn && checkNet)
		return true;
}
bool Net(int arr[9][9])
{
	/*int I[9] = { 0,0,0,6,6,6,9,9,9 };
	int* pI =I;
	int J[9] = { 0,3,6,0,3,6,0,3,6 };
	int* pJ = J;*/
	int RC[9] = { 1,2,3,4,5,6,7,8,9 };
	short n = 3, s = 0;
	for (size_t i = 0; i < 9; i = i + 3)
	{
		for (size_t x = 0; x < 9; x++)
		{
			int sum = 0;
			for (size_t z = 0; z < 3; z++)
			{
				s = 0, n = 3;
				for (size_t j = s; j < 3 + s; j++)
				{
					//cout << RC[x] << "****" << arr[z + i][j] << " z = " << z << "     ";
					if (RC[x] == arr[z + i][j] && arr[z + i][j] > 0 && arr[z + i][j] < 10)
					{
						sum++;
						if (sum > 1)
						{
							//cout <<endl<< "Wrong Number , It is already exist in Same Net!";
							return 0;
						}
					}
					//cout << endl;
				}
			}
			//cout << endl << "================================================" << endl;
			s = s + 3;
			n += 3;
			sum = 0;
			for (size_t z = 0; z < 3; z++)
			{

				for (size_t j = s; j < 3 + s; j++)
				{
					//cout << RC[x] << "****" << arr[z + i][j] << "   ";
					if (RC[x] == arr[z + i][j] && arr[z + i][j] > 0 && arr[z + i][j] < 10)
					{
						sum++;
						if (sum > 1)
						{
							//cout << "Wrong Number , It is already exist in Same Net!";
							return 0;

						}
					}
				}
				//cout << endl;
			}
			//cout << endl << "================================================" << endl;

			s = s + 3;
			n += 3;
			sum = 0;
			for (size_t z = 0; z < 3; z++)
			{

				for (size_t j = s; j < 3 + s; j++)
				{

					//cout << RC[x] << "****" << arr[z + i][j] << "   ";
					if (RC[x] == arr[z + i][j] && arr[z + i][j] > 0 && arr[z + i][j] < 10)
					{

						sum++;
						if (sum > 1)
						{
							//cout << "Wrong Number , It is already exist in Same Net!";
							return 0;
						}
					}
				}
				//cout << endl;
			}
			//cout << endl << endl;

			//cout << endl << "================================================" << endl;

		}
	}
	return true;
}
void showSudoku(int arr[9][9], bool a[9][9])
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
	bool a[9][9] = { false };
	int arr[9][9];
	arr[0][1] = 3, arr[0][2] = 5, arr[0][3] = 4, arr[0][4] = 8, arr[0][7] = 9, arr[0][8] = 2;
	arr[1][2] = 7, arr[1][4] = 2, arr[1][7] = 6;
	arr[2][0] = 2, arr[2][3] = 9, arr[2][6] = 7;
	arr[3][1] = 4, arr[3][2] = 9, arr[3][5] = 8, arr[3][6] = 2;
	arr[4][1] = 5, arr[4][4] = 4, arr[4][5] = 1, arr[4][7] = 7;
	arr[5][2] = 1, arr[5][3] = 5, arr[5][6] = 8, arr[5][7] = 4;
	arr[6][2] = 4, arr[6][5] = 9, arr[6][8] = 5;
	arr[7][1] = 7, arr[7][4] = 1, arr[7][6] = 4;
	arr[8][0] = 9, arr[8][1] = 2, arr[8][4] = 5, arr[8][5] = 4, arr[8][6] = 3, arr[8][7] = 1;
	int m = 0, n = 0;
	int num = 0;
	bool checkRow = true, checkColumn = true, checkNet = true;
	showSudoku(arr, a);
	do
	{
		check(arr);
		if (Net(arr) == false)
			cout << "Wrong , Same Net " << endl;
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

		arr[r - 1][c - 1] = value;       //the value will be stored whether it is correct or wrong


		////////////

		bool busy = true;
		for (size_t i = 0; i < 9; i++)
		{
			for (size_t j = 0; j < 9; j++)
			{
				if (arr[i][j] < 0 || arr[i][j]>9)
				{
					busy = false;
					break;
				}
			}
		}
		if (busy)
		{
			if (check(arr) && Net(arr))
			{
				cout << " GG nice game " << endl << endl;
				break;
			}
		}
		showSudoku(arr, a);
	} while (true);
}
