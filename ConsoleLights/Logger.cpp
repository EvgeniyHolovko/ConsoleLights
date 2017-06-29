#include "stdafx.h"
#include "Logger.h"
#include "windows.h"
#include <iomanip>

using namespace std;

ofstream Logger::logOfstream ("log.txt", ios::app);


void Logger::printLocalDateTime()
{
	SYSTEMTIME systemtime;
	GetLocalTime(&systemtime);
	logOfstream << systemtime.wYear << '.' << setw(2) << setfill('0') << systemtime.wMonth << '.' << setw(2) << setfill('0')
		<< systemtime.wDay << ' ' << setw(2) << setfill('0') << systemtime.wHour << ':' << setw(2) << setfill('0')
		<< systemtime.wMinute << ':' << setw(2) << setfill('0') << systemtime.wSecond << ':' << setw(3) << setfill('0')
		<< systemtime.wMilliseconds;
}

void Logger::info(std::string s)
{
	printLocalDateTime();
	logOfstream << " info: " << s << endl;
}

void Logger::close(void)
{
	logOfstream.close();
}
