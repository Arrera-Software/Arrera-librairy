#pragma once
#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

class CSocketUDP
{
private : 
	SOCKET sock;
	SOCKADDR_IN socketINF;
	bool etat;
public : 
	CSocketUDP(PCSTR IP,int PORT, SOCKADDR_IN *infoSocket);
	CSocketUDP(int PORT, SOCKADDR_IN* infoSocket);
	~CSocketUDP();
	bool sendMessage(char* message, SOCKADDR_IN* infoSocket);
	bool receivedMessage(char* message, SOCKADDR_IN* infoSocket);
};

