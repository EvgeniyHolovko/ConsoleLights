#include "stdafx.h"
#include "lights.h"
#include "Logger.h"


void Lights::messageTick()
{
	if (0 <= counter&&counter <= 19){
		switchOn(RED);
	}

	else if (20 <= counter&&counter <= 69 || 100 <= counter&&counter <= 139) {
		switchOn(YELLOW);
	}

	else if (70 <= counter&&counter <= 99){
		switchOn(GREEN);
	}

	else
	{
		counter = 0;
	}
	counter++;
}

void Lights::messageKey(const TCHAR message)
{
	if (message == pauseChar1 || message == pauseChar2) {
		pause = true;
		blind.show();
	}
	else if (message == startChar1 || message == startChar2) {
		pause = false;
		counter = 0;
		currentColor = RED;
		red.show();
	}
}

void Lights::switchOn(const Color color)
{
	if (pause) return;

	if (currentColor != color)
	{
		currentColor = color;
		switch (color)
		{
		case RED:
			red.show();
			Logger::info("Red light is switched on");
			break;
		case YELLOW:
			yellow.show();
			Logger::info("Yellow light is switched on");
			flash = true;
			break;
		case GREEN:
			green.show();
			Logger::info("Green light is switched on");
			break;
		default:
			blind.show();
		}
	}
	else if (currentColor == YELLOW)
	{
		int i = counter % 10;
		if (flash)
		{
			if (i > 4) blind.show();
			flash = false;
		}
		else
		{
			if (i <= 4) yellow.show();
			flash = true;
		}

	}
}

Lights::Lights() : red(*new Statement(RED)), green(*new Statement(GREEN)), yellow(*new Statement(YELLOW)), blind(*new Statement(BLIND)), counter(0)
{
	red.show();
}

Lights::~Lights()
{
	delete& red;
	delete& green;
	delete& yellow;
	delete& blind;
}
