#pragma once
#include <Windows.h>
#include "Lights.h"
#include <vector>
#include "AbsDevice.h"

const int PERIOD = 100;
const int TICK_TIME = 10000;

const TCHAR		exitChar = 69;		
const TCHAR		exitChar1 = 101;	


class TimerCyclicApp {
public:
	TimerCyclicApp();
	~TimerCyclicApp();
	void run(void);
	void addDevice(AbsDevice*);

private:
	HANDLE hTimer;
	HANDLE hConManager;
	std::vector<AbsDevice*>& appDevices;
	Lights& lights;	

};
