; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPolygonsView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Polygons.h"
LastPage=0

ClassCount=6
Class1=CPolygonsApp
Class2=CPolygonsDoc
Class3=CPolygonsView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CChooseType
Resource3=IDD_DIALOG1

[CLS:CPolygonsApp]
Type=0
HeaderFile=Polygons.h
ImplementationFile=Polygons.cpp
Filter=N
LastObject=CPolygonsApp

[CLS:CPolygonsDoc]
Type=0
HeaderFile=PolygonsDoc.h
ImplementationFile=PolygonsDoc.cpp
Filter=N

[CLS:CPolygonsView]
Type=0
HeaderFile=PolygonsView.h
ImplementationFile=PolygonsView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_POLY_TYPE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Polygons.cpp
ImplementationFile=Polygons.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STAT1,static,1342308352
Control6=IDC_STAT2,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_POLY_TYPE
Command8=ID_APP_ABOUT
CommandCount=8

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_DIALOG1]
Type=1
Class=CChooseType
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[CLS:CChooseType]
Type=0
HeaderFile=ChooseType.h
ImplementationFile=ChooseType.cpp
BaseClass=CDialog
Filter=D
LastObject=CChooseType
VirtualFilter=dWC

