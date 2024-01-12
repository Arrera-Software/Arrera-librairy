// OBJ-OS.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once

#include <iostream>

// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre programme.
class COS
{
private :
	bool ewindows;
	bool elinux;
public :
		COS();
		~COS();
		bool getWindows();
		bool getLinux();
};


COS::COS()
{
#ifdef __linux__
	elinux = true;
	ewindows = false;
#elif _WIN32
	elinux = false;
	ewindows = true;
#else
	elinux = false;
	ewindows = false;
#endif
}

COS::~COS()
{

}

bool COS::getLinux()
{
	return elinux;
}

bool  COS::getWindows()
{
	return ewindows;
}