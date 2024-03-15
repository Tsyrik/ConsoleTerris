#pragma once
#include "Enums.h"
#include <string>
#include <windows.h>
#include <memory>
#include <thread>

class PlayField
{
public:


	void Draw();
	void Initialization();
	void gameStep();
	void moveLeft();
	void moveRight();
	void Rotate();
	void staticTetromino();
	void GetInput();
	void Join();

private:

	int m_playFieldBool[FieldSize::HEIGHT][FieldSize::WIDTH] = {
		{1,0,0,0,5,5,0,0,0,0,0,1,6},
		{1,0,0,0,5,0,0,0,0,0,0,1,6},
		{1,0,0,0,5,0,0,0,0,0,0,1,6},
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
		{1,0,0,0,0,7,0,0,0,0,0,1,6},
		{1,0,0,0,0,7,0,0,0,0,0,1,6},
		{1,0,0,0,0,7,7,0,0,0,0,1,6},
		{1,0,7,0,0,7,7,0,0,7,7,1,6},
		{1,7,7,0,0,7,7,0,0,7,0,1,6},
		{3,2,2,2,2,2,2,2,2,2,2,4,6}
	};

	std::string m_wall, m_block, m_bottom, m_leftBottom, m_rightBottom = "";

	std::string m_space = " ";

	std::string m_fills[8];

	std::string m_canvas;

	HANDLE m_cursorHandle;
	COORD m_cursorInitPosition;

	std::unique_ptr<std::thread> m_inputSignals;

	bool m_gameOver;
	int m_playfield[FieldSize::WIDTH][FieldSize::HEIGHT];
	int m_fieldWidth;
	int m_fieldHight;
	int m_score;
	std::string m_fieldDisplay;
};

