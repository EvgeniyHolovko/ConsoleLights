#pragma once
#include "stdafx.h"
#include <Windows.h>
const TCHAR STUFF_CHAR = 0x2588;                                
const TCHAR topLeftCorner = 0x2554;								
const TCHAR horisontLine = 0x2550;								
const TCHAR topRigthCorner = 0x2557;							
const TCHAR verticalLine = 0x2551;								
const TCHAR verticalLineRigthShoot = 0x2560;					
const TCHAR verticalLineLeftShoot = 0x2563;						
const TCHAR bottomLeftCorner = 0x255A;							
const TCHAR bottomRigthCorner = 0x255D;							
const TCHAR likeTsignUP = 0x2566;							    
const TCHAR likeTsignDOWN = 0x2569;								

const COORD POINT_OF_REFERENCE{35, 1};
const DWORD FOREGROUND_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;


enum Color { RED, GREEN, YELLOW, BLIND };



class Statement
{
public:
	void show(void) const;
	Statement(Color col);	
	~Statement();

private:

	HANDLE hScreen;
	void fillRect(const TCHAR fillChar, const WORD attr, const COORD topLeft, const COORD bottomRight, const bool useAttr) const;
	void drawScreen(const Color col, const HANDLE hScreen) const;

	inline COORD setRefCoord(const int x, const int y) const
	{
		COORD tempCoord = POINT_OF_REFERENCE;
		tempCoord.X += x;
		tempCoord.Y += y;
		return tempCoord;
	}
	


};
