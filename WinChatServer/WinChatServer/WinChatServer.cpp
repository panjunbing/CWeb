// WinChatServer.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int len = sizeof(SOCKADDR);

    bind(sockServer,(SOCKADDR*)&addrServer,len);

    SOCKADDR_IN addrClient;
	char recvIP[32];				//�յ���Ϣ�ߵ�IP
	string sendIP;					//������Ϣ�ߵ�IP
    char buffer[128];				//�����ַ�����
    memset(buffer,'\0',128);
	memset(recvIP,'\0',32);

	cout<<"���ͼ�¼"<<endl;
	while(1){
		//��������
		recvfrom(sockServer,recvIP,32,0,(SOCKADDR*)&addrClient,&len);
		recvfrom(sockServer,buffer,128,0,(SOCKADDR*)&addrClient,&len);
		cout<<inet_ntoa(addrClient.sin_addr)<<"��"<<recvIP<<"���ͣ�"<<buffer<<endl;

		sendIP = inet_ntoa(addrClient.sin_addr);
		addrClient.sin_addr.s_addr = inet_addr(recvIP);
		//��������
		sendto(sockServer,sendIP.c_str(),sendIP.size()+1,0,(SOCKADDR*)&addrClient,len);
		sendto(sockServer,buffer,128,0,(SOCKADDR*)&addrClient,len);
	}

    closesocket(sockServer);
    WSACleanup();

}

