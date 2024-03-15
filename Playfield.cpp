#include "Playfield.h"
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

void PlayField::Initialization()
{

	m_wall += (char)(186);

	m_block += (char)(219);
	m_block += (char)(219);

	m_space += (char)(250);

	m_bottom += (char)(205);
	m_bottom += (char)(205);

	m_leftBottom += (char)(200);

	m_rightBottom += (char)(188);

	m_canvas.reserve(FieldSize::HEIGHT * FieldSize::WIDTH * 2);

	m_fills[0] = m_space;
	m_fills[1] = m_wall;
	m_fills[2] = m_bottom;
	m_fills[3] = m_leftBottom;
	m_fills[4] = m_rightBottom;
	m_fills[5] = m_block;
	m_fills[6] = "\n";
	m_fills[7] = m_block;

	m_cursorHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	m_inputSignals = std::make_unique<std::thread>(&PlayField::GetInput, this);
}


void PlayField::Draw()
{
	m_canvas = "";
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			m_canvas += m_fills[m_playFieldBool[i][j]];
		}
	}
	SetConsoleCursorPosition(std::ref(m_cursorHandle), std::ref(m_cursorInitPosition));
	std::cout << m_canvas << std::endl;
}


void PlayField::gameStep()
{
	for (int i = FieldSize::HEIGHT; i >= 0; --i)
	{
		for (int j = FieldSize::WIDTH; j >= 0; --j)
		{
			if (m_playFieldBool[i][j] == 0)
			{
				if (m_playFieldBool[i - 1][j] == 5 && i - 1 >= 0)
				{
					m_playFieldBool[i][j] = 8;
				}
			}
			if (m_playFieldBool[i][j] == 7 || m_playFieldBool[i][j] == 2)
			{
				if (m_playFieldBool[i - 1][j] == 5)
				{
					staticTetromino();
				}
			}
			if (m_playFieldBool[i][j] == 5 && (m_playFieldBool[i - 1][j] == 0 || i - 1 < 0))
			{
				m_playFieldBool[i][j] = 0;

				int offset = i;
				while (m_playFieldBool[offset][j] != 8)
				{
					++offset;
				}
				m_playFieldBool[offset][j] = 5;
			}
		}
	}
}

void PlayField::moveLeft()
{
	for (int i = FieldSize::HEIGHT; i >= 0; --i)
	{
		for (int j = FieldSize::WIDTH; j >= 0; --j)
		{
			if (m_playFieldBool[i][j] == 5 && m_playFieldBool[i][j - 1] == 0)
			{
				m_playFieldBool[i][j - 1] == 8;
			}
			if (m_playFieldBool[i][j] == 5 && m_playFieldBool[i][j - 1] == 7)
			{

			}
		}
	}
}

void PlayField::moveRight()
{
	for (int i = FieldSize::HEIGHT; i >= 0; --i)
	{
		for (int j = FieldSize::WIDTH; j >= 0; --j)
		{
			if (m_playFieldBool[i][j] == 5 && (m_playFieldBool[i][j + 1] == 0 || j + 1 > 10))
			{
				m_playFieldBool[i][j + 1] == 8;
			}
		}
	}
}

void PlayField::staticTetromino()
{
	for (int i = 0; i < FieldSize::HEIGHT; ++i)
	{
		for (int j = 0; j < FieldSize::WIDTH; ++j)
		{

			if (m_playFieldBool[i][j] == 5)
			{
				m_playFieldBool[i][j] = 7;
			}
			if (m_playFieldBool[i][j] == 8)
			{
				m_playFieldBool[i][j] = 0;
			}
		}
	}
}

void PlayField::Rotate(){}

void PlayField::GetInput()
{
	while (!m_gameOver)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 75:
				moveLeft();
				break;
			case 77:
				moveRight();
				break;
			case 72:
				Rotate();
				break;
			case 80:
				gameStep();
				break;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds{ 50 });
	}
}

void PlayField::Join()
{
	m_inputSignals->join();
	//m_drawField->join();
}