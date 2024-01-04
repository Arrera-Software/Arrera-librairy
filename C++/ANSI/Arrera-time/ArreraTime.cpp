#include "ArreraTime.h"

void ArreraTime::getTime()
{
	temps = time(0);
	localtime_s(&tempsLocal, &temps);
}

ArreraTime::ArreraTime()
{
	temps = time(0); 
	localtime_s(&tempsLocal, &temps);
}

ArreraTime::~ArreraTime()
{
}

int ArreraTime::getHour()
{
	getTime();
	return tempsLocal.tm_hour;
}

int ArreraTime::getMin()
{
	getTime();
	return tempsLocal.tm_min;
}

int ArreraTime::getSec()
{
	getTime();
	return tempsLocal.tm_sec;
}

int ArreraTime::getYears()
{
	getTime();
	return tempsLocal.tm_year;
}

string ArreraTime::getDay()
{
	getTime();
	int sortie = tempsLocal.tm_wday;
	switch (sortie)
	{
	case 1 :
		return "Lundi";
	case 2 :
		return "Mardi";
	case 3:
		return "Mercredi";
	case 4:
		return "Jeudi";
	case 5:
		return "Vendredi";
	case 6:
		return "Samedi";
	case 7:
		return "Dimanche";
	}
}

string ArreraTime::getMonth()
{
	int sortie = tempsLocal.tm_mon;
	switch (sortie)
	{
	case 0:
		return "Janvier";
	case 1:
		return "Fevrier";
	case 2:
		return "Mars";
	case 3:
		return "Avril";
	case 4:
		return "Mai";
	case 5:
		return "Juin";
	case 6:
		return "Juillet";
	case 7:
		return "Aout";
	case 8:
		return "Septembre";
	case 9:
		return "Novembre";
	case 10:
		return "Decembre";
	}
}
