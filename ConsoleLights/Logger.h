#pragma once
#include <string>
#include <fstream>


class Logger 
{
public:
	static void info(std::string s);
	static void close(void);

private:
	static std::ofstream logOfstream;
	static void	printLocalDateTime();

};