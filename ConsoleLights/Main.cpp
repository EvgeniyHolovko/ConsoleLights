#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "Statement.h"
#include "TimerCyclicApp.h"
#include "Lights.h"
#include "Logger.h"


int main() {

	TimerCyclicApp& app = *new TimerCyclicApp();
	AbsDevice* lightsPtr = new Lights;

	app.addDevice(lightsPtr);
	app.run();

	delete lightsPtr;
	delete& app;
	Logger::close();
	return 0;
}