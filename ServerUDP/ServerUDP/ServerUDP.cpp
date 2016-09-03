// ServerUDP.cpp : 定义控制台应用程序的入口点。
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
    char recvBuffer[128];//接收字符数据
    memset(recvBuffer,'\0',128);
    cout<<"等待客户端发送数据"<<endl;

	while(1){
		//接收数据
		recvfrom(sockServer,recvBuffer,128,0,(SOCKADDR*)&addrClient,&len);
		cout<<"客户端："<<recvBuffer<<endl;
		//发送数据
		string sendBuffer = "收到数据";
		cout<<"服务器："<<sendBuffer.c_str()<<endl;
		sendto(sockServer,sendBuffer.c_str(),sendBuffer.length() +1,0,(SOCKADDR*)&addrClient,len);
	}

    closesocket(sockServer);
    WSACleanup();

}
