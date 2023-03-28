#include "CChrono.h"
#include <time.h>
#include <stdio.h>
#include <iostream>

using namespace std;

CChrono::CChrono()
{
	etat = false;
	clockStart = 0;
	clockStop = 0;
}
CChrono::~CChrono()
{

}
bool CChrono::Start()
{
	if (etat == false)
	{
		clockStart = clock();
		etat = true;
		return true;
	}
	else
	{
		return false;
	}
}
	
bool CChrono::Stop()

{
	if (etat == true)
	{
		clockStop = clock();
		etat = false;
		return true;
	}
	else 
	{
		return false;
	}
	
}
bool CChrono::Reset()
{
	clockStart = 0;
	clockStop = 0;
	etat = false;
	return true;

}
void CChrono::lireTemps(unsigned short* h, int* mn, int* s, int* c)
{
	int secondes, iCentiemes;
	float fCentieme;
	if (etat == true)
	{
		fCentieme = ( clock() - clockStart) / CLOCKS_PER_SEC;
		secondes = fCentieme;
		iCentiemes = (fCentieme - secondes) * 100;
	}
	else
	{
		if (etat == false)
		{
			fCentieme = (clockStop - clockStart) / CLOCKS_PER_SEC;
			secondes = fCentieme;
			iCentiemes = (fCentieme - secondes) * 100;
		}

	}
	*h = secondes / 3600;
	*mn = (secondes % 3600) / 60;
	*s = secondes % 60;
	*c = iCentiemes;

}
bool CChrono::lireTemps(char* temp, int* taille)

{
	int secondes;
	int minutes, heures, jours, iCentiemes,i;
	float fCentieme;
	char chaine[12];
	if (*taille >= 11) 
	{
		if (etat == true)
		{
			fCentieme = (clock() - clockStart) / CLOCKS_PER_SEC;
			secondes = fCentieme;
			iCentiemes = (fCentieme - secondes) * 100;
			heures = secondes / 3600;
			minutes = (secondes % 3600) / 60;
			secondes = secondes % 60;
		}
		else
		{
			if (etat == false)
			{
				fCentieme = (clockStop - clockStart) / CLOCKS_PER_SEC;
				secondes = fCentieme;
				iCentiemes = (fCentieme - secondes) * 100;
				heures = secondes / 3600;
				minutes = (secondes % 3600) / 60;
				secondes = secondes % 60;
			}

		}
		sprintf_s(chaine, "%d:%d:%d.%d", heures, minutes, secondes, iCentiemes);
		for (i = 0; i <= 11; i++)
		{
			temp[i] = chaine[i];
		}
		temp[i] = '\0';
		
		return true;
	}
	else
	{
		return false;

	}
}