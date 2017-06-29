#include "stdafx.h"
#include "TimerCyclicApp.h"
#include <vector>

TimerCyclicApp::TimerCyclicApp(): appDevices(*new std::vector<AbsDevice*>), lights(*new Lights)
{
	hTimer = CreateWaitableTimer(nullptr, false, nullptr);
	hConManager = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hConManager, &mode);
	mode &= ~ENABLE_ECHO_INPUT;
	SetConsoleMode(hConManager, mode);
}

TimerCyclicApp::~TimerCyclicApp()
{
	CloseHandle(hTimer);
	delete& lights;
	delete& appDevices;
}

void TimerCyclicApp::run(void)
{
	LARGE_INTEGER li;
	li.QuadPart = -(TICK_TIME * PERIOD);
	SetWaitableTimer(hTimer, &li, PERIOD, nullptr, nullptr, false);
	DWORD numberOfEvents;
	INPUT_RECORD irInBuf[10];

	while (true)
	{
		bool keyEvent = false;
		TCHAR receivedChar = 0;
		if (GetNumberOfConsoleInputEvents(hConManager, &numberOfEvents)) {
			if (numberOfEvents > 0 && ReadConsoleInput(hConManager, irInBuf, 10, &numberOfEvents)) {
				if (numberOfEvents > 0) {				
					for (UINT i = 0; i < numberOfEvents; i++) {
						if (irInBuf[i].EventType == KEY_EVENT)
						{
							keyEvent = true;
							receivedChar = irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
							break;
						}
					}
				}
			}
		}

		if (keyEvent && receivedChar == exitChar || receivedChar == exitChar1) { return; }

		for (AbsDevice* app_devices_ptr : appDevices)
		{
			app_devices_ptr->messageTick();
			if (keyEvent) {
				app_devices_ptr->messageKey(receivedChar);
			}
		}

		WaitForSingleObject(hTimer, INFINITE);
	}

}

void TimerCyclicApp::addDevice(AbsDevice* devicePtr)
{
	appDevices.push_back(devicePtr);
}
