// WinChatClient.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Winsock2.h>
#include <iostream>
#include <string>
#include <process.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

SOCKET sockClient;
SOCKADDR_IN addrSrv;
int len = sizeof(SOCKADDR);

void _cdecl recv(void* param){
	while(1){
		char recvIP[32];			//给自己发送消息对象的IP
		char recvBuffer[300];		//接收字符数据
		memset(recvIP,0,32);
		memset(recvBuffer,'\0',300);

		//接收数据
		if(recvfrom(sockClient,recvIP,32,0,(SOCKADDR*)&addrSrv,&len) == -1)
			continue;
		recvfrom(sockClient,recvBuffer,300,0,(SOCKADDR*)&addrSrv,&len);
		cout<<recvIP<<"向你发送消息："<<recvBuffer<<endl;
	}
}

void main()
{
    WORD wVersionRequested;
    WSADATA wsaData;

    wVersionRequested = MAKEWORD( 1, 1 );
    WSAStartup( wVersionRequested, &wsaData );

    //建立通讯 socket
    sockClient=socket(AF_INET,SOCK_DGRAM,0);
    addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(6000);

	//bind(sockClient,(SOCKADDR*)&addrSrv,len);
	HANDLE handle = (HANDLE)_beginthread(recv,0,0);

	while(1){
		//发送数据
		string sendIP;				//发送对象的IP
		string buffer;				//发送的字符数据

		cout<<"请输入对方IP和发送内容(输入#q退出)"<<endl;
		cin>>sendIP;
		if(sendIP == "#q")
			break;
		cin>>buffer;
		if(buffer == "#q")
			break;
		if(sendto(sockClient,sendIP.c_str(),sendIP.length()+1,0,(SOCKADDR*)&addrSrv,len) == -1){
			cout<<"发送失败！"<<endl;
			continue;
		}
		sendto(sockClient,buffer.c_str(),buffer.length()+1,0,(SOCKADDR*)&addrSrv,len);
	}

    closesocket(sockClient);
    WSACleanup();
}

