// ClientUDP.cpp : 定义控制台应用程序的入口点。
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

    //建立通讯 socket
    SOCKET sockClient=socket(AF_INET,SOCK_DGRAM,0);
    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=inet_addr("192.168.1.101");
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(6000);
	int len = sizeof(addrSrv);

	while(1){
		//发送数据
		string buffer;
		cout<<"请输入发送内容"<<endl<<"客户端：";
		cin>>buffer;
		sendto(sockClient,buffer.c_str(),buffer.length()+1,0,(SOCKADDR*)&addrSrv,len);

		//接收数据
		char recvBuffer[300];//接收字符数据
		memset(recvBuffer,'\0',300);
		recvfrom(sockClient,recvBuffer,300,0,(SOCKADDR*)&addrSrv,&len);
		cout<<"服务器： "<<recvBuffer<<endl;
	}

    closesocket(sockClient);
    WSACleanup();
    system("pause");
}

