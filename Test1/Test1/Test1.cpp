// Test1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	PHOSTENT    hostinfo;		//������Ϣ
	char        name[32];		//������

	WORD wVersionRequested=MAKEWORD(2,2);  
	WORD Result=WSAStartup(wVersionRequested, &wsaData);  

	if(gethostname(name,sizeof(name)) == 0){
//		if((hostinfo = gethostbyname(name))!= NULL){  
			cout<<"������Ϊ��"<<name<<endl;
//			cout<<"������IPΪ��"<<endl;
//			for(int i = 0;hostinfo->h_addr_list[i] != NULL;i++){							//����ÿһ��IP��ַ
//				cout<<inet_ntoa(*(struct in_addr *)hostinfo->h_addr_list[i])<<endl;   
//			}
//		}
	}
	WSACleanup();

	IP_ADAPTER_INFO adapter[8];													//����˸�������Info�Ŀռ�
    DWORD size=sizeof(adapter);
    DWORD status=GetAdaptersInfo(adapter,&size);
    if(!status)
    {
        IP_ADAPTER_INFO *p = adapter;											//ָ���׸�������
		while(p){																//����ÿһ��������
			cout<<p->Description<<":"<<endl<<"MAC:";
			for(int i = 0;i<8;i++){
				cout<<hex<<(int)p->Address[i]<<"-";									//��ȡMAC��ַ(16����)
			}
			cout<<endl<<"IP:"<<p->IpAddressList.IpAddress.String<<endl;			//��ȡIP��ַ
			cout<<endl;
			p = p->Next;
		}
    }

	return 0;

}


	int func(x){
	
		return 0;
	}



   


