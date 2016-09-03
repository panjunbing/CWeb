// WinChatServer.cpp : 定义控制台应用程序的入口点。
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
	char recvIP[32];				//收到消息者的IP
	string sendIP;					//发送消息者的IP
    char buffer[128];				//接收字符数据
    memset(buffer,'\0',128);
	memset(recvIP,'\0',32);

	cout<<"发送记录"<<endl;
	while(1){
		//接收数据
		recvfrom(sockServer,recvIP,32,0,(SOCKADDR*)&addrClient,&len);
		recvfrom(sockServer,buffer,128,0,(SOCKADDR*)&addrClient,&len);
		cout<<inet_ntoa(addrClient.sin_addr)<<"向"<<recvIP<<"发送："<<buffer<<endl;

		sendIP = inet_ntoa(addrClient.sin_addr);
		addrClient.sin_addr.s_addr = inet_addr(recvIP);
		//发送数据
		sendto(sockServer,sendIP.c_str(),sendIP.size()+1,0,(SOCKADDR*)&addrClient,len);
		sendto(sockServer,buffer,128,0,(SOCKADDR*)&addrClient,len);
	}

    closesocket(sockServer);
    WSACleanup();

}

