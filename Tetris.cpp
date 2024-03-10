#include <iostream>
#include "Enums.h"
#include <string>
#include "Playfield.h"
#include <thread>
#include <chrono>


int main ()
{

	PlayField field;
	field.Initialization();

	for (int i = 0; i < 100; ++i)
	{
		field.Draw();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		field.moveTetromino();
	}




	//std::cout << "(char)(219): " << (char)(219) << std::endl;


	/*
	for (int i = 0; i < 256; ++i)
	{
		std::cout << "(char)("<<i<<"): " << (char)(i) << " static_cast<char>(" << i << "): " << static_cast<char>(i) << std::endl;

	}
*/



/*
std::string wall = "";
wall += (char)(186);

std::string block = "";
block += (char)(219);
block += (char)(219);

std::string space = " ";
space += (char)(250);

std::string space2 = "";
space2 += (char)(176);
space2 += (char)(176);

std::string bottom = "";
bottom += (char)(205);
bottom += (char)(205);

std::string leftBottom = "";
leftBottom += (char)(200);

std::string rightBottom = "";
rightBottom += (char)(188);

std::string field1 = "";
std::string field2 = "";

int hight = 21;
int widgth = 12;


bool coordsL0[4][8] = {
	{0,0,0,0,1,1,0,0},
	{1,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};


int vertCount = 1;

for (int i = 0; i < hight; ++i)
{
	if (i == hight - 1)
	{
		for (int j = 0; j < widgth; ++j)
		{
			if (j == 0)
			{
				field1 += leftBottom;
			}
			else if (j == widgth - 1)
			{
				field1 += rightBottom;
			}
			else
			{
				field1 += bottom;
			}
		}


	}
	else
	{
		for (int j = 0; j < widgth; ++j)
		{
			if (j == 0 || j == widgth - 1)
			{
				field1 += wall;
			}
			else
			{
				field1 += space;
			}

		}
	}

	field1 += std::to_string (vertCount);
	field1 += "\n";
	++vertCount;
}


std::cout << field1 << std::endl;
*/




	std::string wall = "";
	wall += (char)(186);

	std::string block = "";
	block += (char)(219);
	block += (char)(219);

	std::string space = " ";
	space += (char)(250);

	std::string space2 = "";
	space2 += (char)(176);
	space2 += (char)(176);

	std::string bottom = "";
	bottom += (char)(205);
	bottom += (char)(205);

	std::string leftBottom = "";
	leftBottom += (char)(200);

	std::string rightBottom = "";
	rightBottom += (char)(188);

	std::string fills[] = {
		space,
		wall,
		bottom,
		leftBottom,
		rightBottom,
		block,
		"\n"
	};



	int playFieldBool[21][13] = {
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,5,0,0,0,0,0,0,0,1,6},
		{1,0,0,5,0,0,0,0,0,0,0,1,6},
		{1,0,0,5,5,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{1,0,0,0,0,0,0,0,0,0,0,1,6},
		{3,2,2,2,2,2,2,2,2,2,2,4,6}
	};


	std::string canvas = "";
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			canvas += fills[playFieldBool[i][j]];
		}
	}

	std::cout << canvas << std::endl;

}
