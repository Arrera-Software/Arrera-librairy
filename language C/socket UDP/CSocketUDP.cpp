#include "CSocketUDP.h" 

CSocketUDP::CSocketUDP(PCSTR IP, int PORT, SOCKADDR_IN *infoSocket)
{
	int retour;
	WSADATA dataws;
	ULONG addr; 
	retour = WSAStartup(MAKEWORD(2, 2),&dataws) ;
	if (retour == 0)
	{
		sock = socket(AF_INET, SOCK_DGRAM, 0);
		if (sock != INVALID_SOCKET)
		{
			infoSocket->sin_port = htons(2000);
			infoSocket->sin_family = AF_INET;
			inet_pton(AF_INET,IP, &addr);
			inet_pton(AF_INET, IP, &addr);
			infoSocket->sin_addr.s_addr = addr;
			infoSocket->sin_port = htons(PORT);
			etat = true;
		}
		else
		{
			etat = false;
		}
	}
	else
	{
		etat = false;
	}
}

CSocketUDP::~CSocketUDP()
{

}

CSocketUDP::CSocketUDP(int PORT, SOCKADDR_IN* infoSocket)
{
	int retour; 
	WSADATA dataws;  
	ULONG addr; 
	retour = WSAStartup(MAKEWORD(2, 2), &dataws);
	if (retour == 0)
	{
		sock = socket(AF_INET, SOCK_DGRAM, 0);
		if (sock != INVALID_SOCKET)
		{
			infoSocket->sin_family = AF_INET;
			infoSocket->sin_addr.s_addr = INADDR_ANY;
			infoSocket->sin_port = htons(2000);
			if (bind(sock, (sockaddr*)infoSocket, sizeof(sockaddr)) == SOCKET_ERROR)
			{
				etat = true;
			}
			else
			{
				etat = false;
			}
		}
		else
		{
			etat = false;
		}
	}
	else
	{
		etat = false;
	}

}

bool CSocketUDP::sendMessage(char* message, SOCKADDR_IN* infoSocket)
{
	int tailleOctet = sizeof(sockaddr);
	if (etat == true)
	{
		sendto(sock, message, (strlen(message) + 1), 0, (sockaddr*)infoSocket, tailleOctet);
		return true;
	}
	else
	{
		return false;
	}
	
}

bool CSocketUDP::receivedMessage(char* message, SOCKADDR_IN* infoSocket)
{
	int tailleOctet = sizeof(sockaddr);
	if (etat == true) 
	{
		recvfrom(sock, message, 20, 0, (sockaddr*)infoSocket, &tailleOctet);
		return true;
	}
	else
	{
		return false;
	}
	
}