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

	

	for (int i = 0; i < 30; ++i)
	{
		field.Draw();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		field.gameStep();
	}
	field.Join();
	return 0;
}
