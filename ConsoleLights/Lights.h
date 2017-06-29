#pragma once
#include "stdafx.h"
#include "statement.h"
#include <vector>
#include "AbsDevice.h"

using namespace std;

class Lights : public AbsDevice
{
public:
	void messageTick();
	void messageKey(const TCHAR message);
	void switchOn(const Color col);
	Lights() ;
	~Lights();

private:

	const TCHAR pauseChar1 = 80;
	const TCHAR pauseChar2 = 112;
	const TCHAR startChar1 = 83;
	const TCHAR startChar2 = 115;

	int counter;
	bool pause;
	bool flash;
	Color currentColor;
	Statement& red;
	Statement& green;
	Statement& yellow;
	Statement& blind;
};
