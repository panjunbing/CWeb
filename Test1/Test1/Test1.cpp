// Test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <WinSock.h>
#include <Windows.h>
#include <Iphlpapi.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")
using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

	WSADATA     wsaData;  
	PHOSTENT    hostinfo;		//主机信息
	char        name[32];		//主机名

	WORD wVersionRequested=MAKEWORD(2,2);  
	WORD Result=WSAStartup(wVersionRequested, &wsaData);  

	if(gethostname(name,sizeof(name)) == 0){
//		if((hostinfo = gethostbyname(name))!= NULL){  
			cout<<"主机名为："<<name<<endl;
//			cout<<"本机的IP为："<<endl;
//			for(int i = 0;hostinfo->h_addr_list[i] != NULL;i++){							//遍历每一个IP地址
//				cout<<inet_ntoa(*(struct in_addr *)hostinfo->h_addr_list[i])<<endl;   
//			}
//		}
	}
	WSACleanup();

	IP_ADAPTER_INFO adapter[8];													//分配八个适配器Info的空间
    DWORD size=sizeof(adapter);
    DWORD status=GetAdaptersInfo(adapter,&size);
    if(!status)
    {
        IP_ADAPTER_INFO *p = adapter;											//指向首个适配器
		while(p){																//遍历每一个适配器
			cout<<p->Description<<":"<<endl<<"MAC:";
			for(int i = 0;i<8;i++){
				cout<<hex<<(int)p->Address[i]<<"-";									//获取MAC地址(16进制)
			}
			cout<<endl<<"IP:"<<p->IpAddressList.IpAddress.String<<endl;			//获取IP地址
			cout<<endl;
			p = p->Next;
		}
    }

	return 0;

}


	int func(x){
	
		return 0;
	}



   


