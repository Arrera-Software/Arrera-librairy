#pragma once
#include <ctime>
#include <locale>
#include <string>

using namespace std
;
class ArreraTime
{
private :
	time_t temps;
	struct tm tempsLocal;
	void getTime();
public :
	ArreraTime();
	~ArreraTime();
	int getHour();
	int getMin();
	int getSec();
	int getYears();
	string getDay();
	string getMonth();
};

