// ServerUDP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Winsock2.h>
#include <iostream>
#include <string>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

void main()
{
    WORD wVersionRequested;
    WSADATA wsaData;

    wVersionRequested = MAKEWORD( 1, 1 );
    WSAStartup( wVersionRequested, &wsaData );

    SOCKET sockServer=socket(AF_INET,SOCK_DGRAM,0);
    SOCKADDR_IN addrServer;
    addrServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrServer.sin_family = AF_INET;
    addrServer.sin_port = htons(6000);
	int len = sizeof(addrServer);

    bind(sockServer,(SOCKADDR*)&addrServer,len);

    SOCKADDR_IN addrClient;
    char recvBuffer[128];//�����ַ�����
    memset(recvBuffer,'\0',128);
    cout<<"�ȴ��ͻ��˷�������"<<endl;

	while(1){
		//��������
		recvfrom(sockServer,recvBuffer,128,0,(SOCKADDR*)&addrClient,&len);
		cout<<"�ͻ��ˣ�"<<recvBuffer<<endl;
		//��������
		string sendBuffer = "�յ�����";
		cout<<"��������"<<sendBuffer.c_str()<<endl;
		sendto(sockServer,sendBuffer.c_str(),sendBuffer.length() +1,0,(SOCKADDR*)&addrClient,len);
	}

    closesocket(sockServer);
    WSACleanup();

}
