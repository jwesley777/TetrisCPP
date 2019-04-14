// TetrisCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <vector>

void cgoto(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


class Brick
{
public:
	int x;
	int y;
	
public:
	Brick(int x, int y) : x(x), y(y) {}
	void Print()
	{
		cgoto(x, y);
		std::cout << 'o';
	}
};

class Block
{
public:
	virtual void Print() 
	{
		for (Brick b: map) 
		{
			b.Print();
		}
	}
	virtual void MoveLeft()
	{
		int dx = -1;
		for (Brick b : map)
		{
			b.x += dx;
		}
	}
	virtual void MoveRight()
	{
		int dx = +1;
		for (Brick b : map)
		{
			b.x += dx;
		}
	}
	virtual void MoveDown()
	{
		int dy = -1;
		for (Brick b : map)
		{
			b.y += dy;
		}
	}
protected:
	std::vector<Brick> map;
};

class Block1 : public Block
{

};

class Block2 : public Block
{

};


///////////////
const int mapwidth = 10;
const int mapheight = 20;
const int mapsize = mapwidth * mapheight;

int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
