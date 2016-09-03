; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Internet Explorer.h"
LastPage=0

ClassCount=6
Class1=CInternetExplorerApp
Class2=CInternetExplorerDoc
Class3=CInternetExplorerView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CDlg
Resource2=IDD_ABOUTBOX

[CLS:CInternetExplorerApp]
Type=0
HeaderFile=Internet Explorer.h
ImplementationFile=Internet Explorer.cpp
Filter=N

[CLS:CInternetExplorerDoc]
Type=0
HeaderFile=Internet ExplorerDoc.h
ImplementationFile=Internet ExplorerDoc.cpp
Filter=N

[CLS:CInternetExplorerView]
Type=0
HeaderFile=Internet ExplorerView.h
ImplementationFile=Internet ExplorerView.cpp
Filter=C
BaseClass=CHtmlView
VirtualFilter=7VWC
LastObject=CInternetExplorerView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=C
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Internet Explorer.cpp
ImplementationFile=Internet Explorer.cpp
Filter=D
LastObject=ID_SET_HOME

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_SETUP
Command7=ID_FILE_MRU_FILE1
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_GO_FORWARD
Command14=ID_GO_BACK
Command15=ID_GO_REFRESH
Command16=ID_GO_STOP
Command17=ID_HOME
Command18=ID_APP_ABOUT
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_GO_FORWARD
Command2=ID_GO_BACK
Command3=ID_GO_REFRESH
Command4=ID_GO_STOP
Command5=ID_GO_HOME
Command6=ID_APP_ABOUT
CommandCount=6

[CLS:CDlg]
Type=0
HeaderFile=Dlg.h
ImplementationFile=Dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlg

