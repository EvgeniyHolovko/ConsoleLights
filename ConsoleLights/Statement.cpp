#include "stdafx.h"
#include "Statement.h"



void Statement::fillRect(const TCHAR fillChar, const WORD attr, const COORD topLeft, const COORD bottomRight, const bool useAttr) const
{
	DWORD amountOfWrittenChars;
	for (COORD coord = topLeft; coord.Y <= bottomRight.Y; ++coord.Y) {
		FillConsoleOutputCharacter(hScreen, fillChar, bottomRight.X - topLeft.X, coord, &amountOfWrittenChars);
		if (useAttr) {
			FillConsoleOutputAttribute(hScreen, attr, bottomRight.X - topLeft.X, coord, &amountOfWrittenChars);
		}
	}	
}

void Statement::drawScreen(const Color col, const HANDLE hScreen) const
{	

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hScreen, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hScreen, &cursorInfo);


	fillRect(topLeftCorner, 0, setRefCoord(0, 0), setRefCoord(1, 0), false);
	fillRect(horisontLine, 0, setRefCoord(1, 0), setRefCoord(10, 0), false);
	fillRect(topRigthCorner, 0, setRefCoord(10, 0), setRefCoord(11, 0), false);
	fillRect(verticalLine, 0, setRefCoord(0, 1), setRefCoord(1, 5), false);
	fillRect(verticalLine, 0, setRefCoord(10, 1), setRefCoord(11, 5), false);
	fillRect(verticalLineRigthShoot, 0, setRefCoord(0, 6), setRefCoord(1, 6), false);
	fillRect(verticalLineLeftShoot, 0, setRefCoord(10, 6), setRefCoord(11, 6), false);
	fillRect(horisontLine, 0, setRefCoord(1, 6), setRefCoord(10, 6), false);
	fillRect(verticalLine, 0, setRefCoord(0, 7), setRefCoord(1, 11), false);
	fillRect(verticalLine, 0, setRefCoord(10, 7), setRefCoord(11, 11), false);
	fillRect(verticalLineRigthShoot, 0, setRefCoord(0, 12), setRefCoord(1, 12), false);
	fillRect(verticalLineLeftShoot, 0, setRefCoord(10, 12), setRefCoord(11, 12), false);
	fillRect(horisontLine, 0, setRefCoord(1, 12), setRefCoord(10, 12), false);
	fillRect(verticalLine, 0, setRefCoord(0, 13), setRefCoord(1, 17), false);
	fillRect(verticalLine, 0, setRefCoord(10, 13), setRefCoord(11, 17), false);
	fillRect(bottomLeftCorner, 0, setRefCoord(0, 18), setRefCoord(1, 18), false);
	fillRect(horisontLine, 0, setRefCoord(1, 18), setRefCoord(10, 18), false);
	fillRect(bottomRigthCorner, 0, setRefCoord(10, 18), setRefCoord(11, 18), false);
	fillRect(likeTsignUP, 0, setRefCoord(5, 18), setRefCoord(6, 18), false);
	fillRect(verticalLine, 0, setRefCoord(5, 19), setRefCoord(6, 21), false);
	fillRect(horisontLine, 0, setRefCoord(1, 22), setRefCoord(10, 22), false);
	fillRect(likeTsignDOWN, 0, setRefCoord(5, 22), setRefCoord(6, 22), false);

	switch (col)
	{
	case RED:
		fillRect(STUFF_CHAR, FOREGROUND_RED | FOREGROUND_INTENSITY, setRefCoord(1, 1), setRefCoord(10, 5), true);
		break;
	case GREEN:
		fillRect(STUFF_CHAR, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(1, 13), setRefCoord(10, 17), true);
		break;
	case YELLOW:
		fillRect(STUFF_CHAR, FOREGROUND_YELLOW | FOREGROUND_INTENSITY, setRefCoord(1, 7), setRefCoord(10, 11), true);
		break;
	case BLIND:
		break;
	default:
		break;
	}
}


void Statement::show() const
{
	SetConsoleActiveScreenBuffer(hScreen);
}


Statement::Statement(Color col)
{
	hScreen = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	drawScreen(col, hScreen);
}



Statement::~Statement()
{
	CloseHandle(hScreen);
}



