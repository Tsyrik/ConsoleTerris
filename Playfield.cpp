#include "Playfield.h"
#include <iostream>
#include <cstdlib>



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
	system("cls");
	std::cout << m_canvas << std::endl;
}


void PlayField::moveTetromino()
{
	for (int i = FieldSize::HEIGHT; i >= 0; --i)
	{
		for (int j = FieldSize::WIDTH; j >= 0; --j)
		{
			if (m_playFieldBool[i][j] == 0)
			{
				if (m_playFieldBool[i - 1][j] == 5 && i-1>=0)
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



