/*
Roy Smith
Random walk/random map program
2/27/14
*/


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//prototypes
void initMap();
void drawMap();
void nextSpot();
void walk();





const int ROWS = 100;
const int COLUMNS = 100;
char map[ROWS][COLUMNS];

int main()
{
	int times;
	srand(time(NULL));
	
	initMap();
	
	///use this code for random pick from entire map
	
	//for (int i = 0; i < ((ROWS * COLUMNS) / 2); i++)
		//nextSpot();
	
	///end full random code
		
	
	///use this code for random walk from origin
	
	cout << "How many times to walk?" << endl;
	cin >> times;
	
	for (int i = 0; i < times; i++)
		walk();
	
	///end walk code
	
	drawMap();

	return 0;
}

//function to set map to all blanks except for corners
void initMap()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			map[i][j] = ' ';
		}
	}
	
	//show bounds of map
	map[0][0] = '*';
	map[0][99] = '*';
	map[99][99] = '*';
	map[99][0] = '*';
}

//function to draw map to screen
void drawMap()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << map[i][j] << ' '; 
		}
		cout << endl;
	}
}

//function to choose next spot (used if picking random spots form entire map)
void nextSpot()
{
	int row = rand() % ROWS;
	int col = rand() % COLUMNS;
	
	map[row][col] = '-';
	
}

//functions to walk in a direction (used for random walk)
void walk()
{
	int direction;
	static int startRow = ROWS / 2;
	static int startCol = COLUMNS / 2;
	
	direction = rand() % 4;
	
	if (direction == 0)
	{
		if (startRow + 1 < ROWS)
			startRow++;
		map[startRow][startCol] = '-';
	}
	else if (direction == 1)
	{
		if (startCol + 1 < COLUMNS)
			startCol++;
		map[startRow][startCol] = '-';
	}
	else if (direction == 2)
	{
		if (startRow - 1 > 0)
			startRow--;
		map[startRow][startCol] = '-';
	}
	else if (direction == 3)
	{
		if (startCol - 1 > 0)
			startCol--;
		map[startRow][startCol] = '-';
	}
	
}
