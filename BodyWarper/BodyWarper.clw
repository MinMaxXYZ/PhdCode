; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BodyWarper.h"
LastPage=0

ClassCount=7
Class1=CBodyWarperApp
Class2=CBodyWarperDoc
Class3=CBodyWarperView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_BODYWATYPE
Class5=CAboutDlg
Class6=CChildFrame
Resource4=IDR_BODYWATYPE (English (U.S.))
Resource5=IDD_INSUFFICIENTLANDMARKSDIALOG
Resource6=IDR_MAINFRAME (English (U.S.))
Class7=CInsufficientLandmarksDlg
Resource7=IDD_ABOUTBOX (English (U.S.))

[CLS:CBodyWarperApp]
Type=0
HeaderFile=BodyWarper.h
ImplementationFile=BodyWarper.cpp
Filter=N
LastObject=CBodyWarperApp

[CLS:CBodyWarperDoc]
Type=0
HeaderFile=BodyWarperDoc.h
ImplementationFile=BodyWarperDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CBodyWarperDoc

[CLS:CBodyWarperView]
Type=0
HeaderFile=BodyWarperView.h
ImplementationFile=BodyWarperView.cpp
Filter=C
LastObject=ID_FILE_CALCULATETRANSFORMATION

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M

[CLS:CAboutDlg]
Type=0
HeaderFile=BodyWarper.cpp
ImplementationFile=BodyWarper.cpp
Filter=D
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
CommandCount=8
Command8=ID_APP_ABOUT

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
CommandCount=8
Command8=ID_APP_ABOUT

[MNU:IDR_BODYWATYPE]
Type=1
Class=CBodyWarperView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
CommandCount=21
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT

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
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE


[MNU:IDR_BODYWATYPE (English (U.S.))]
Type=1
Class=CBodyWarperView
Command1=ID_FILE_NEW
Command2=ID_FILE_RELOAD
Command3=ID_FILE_IMPORT
Command4=ID_FILE_CLOSE
Command5=ID_FILE_SAVE
Command6=ID_FILE_SAVE_AS
Command7=ID_FILE_LOADSOURCESHAPE
Command8=ID_FILE_LOADSOURCELANDMARKS
Command9=ID_FILE_LOADTARGETSHAPE
Command10=ID_FILE_LOADTARGETLANDMARKS
Command11=ID_FILE_CALCULATETRANSFORMATION
Command12=ID_FILE_LOADTRANSFORMATION
Command13=ID_FILE_SAVETRANSFORMATION
Command14=ID_FILE_PRINT
Command15=ID_FILE_PRINT_PREVIEW
Command16=ID_FILE_PRINT_SETUP
Command17=ID_FILE_INFO
Command18=ID_APP_EXIT
Command19=ID_EDIT_UNDO
Command20=ID_EDIT_CUT
Command21=ID_EDIT_COPY
Command22=ID_EDIT_PASTE
Command23=ID_VIEW_SOURCESHAPE_SOLID
Command24=ID_VIEW_SOURCESHAPE_WIREFRAME
Command25=ID_VIEW_SOURCESHAPE_POINTS
Command26=ID_VIEW_SOURCESHAPE_HIDE
Command27=ID_VIEW_SOURCELANDMARKS
Command28=ID_VIEW_TARGETSHAPE_SOLID
Command29=ID_VIEW_TARGETSHAPE_WIREFRAME
Command30=ID_VIEW_TARGETSHAPE_POINTS
Command31=ID_VIEW_TARGETSHAPE_HIDE
Command32=ID_VIEW_TARGETLANDMARKS
Command33=ID_VIEW_WARPEDSHAPE_SOLID
Command34=ID_VIEW_WARPEDSHAPE_WIREFRAME
Command35=ID_VIEW_WARPEDSHAPE_POINTS
Command36=ID_VIEW_WARPEDSHAPE_HIDE
Command37=ID_VIEW_TOOLBAR
Command38=ID_VIEW_STATUS_BAR
Command39=ID_VIEW_PICEDIT
Command40=ID_WINDOW_NEW
Command41=ID_WINDOW_CASCADE
Command42=ID_WINDOW_TILE_HORZ
Command43=ID_WINDOW_ARRANGE
Command44=IDM_VIEWPOINTS
Command45=ID_APP_ABOUT
CommandCount=45

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_RELOAD
Command4=ID_FILE_IMPORT
Command5=ID_FILE_PRINT_SETUP
Command6=ID_FILE_MRU_FILE1
Command7=ID_FILE_INFO
Command8=ID_APP_EXIT
Command9=ID_VIEW_TOOLBAR
Command10=ID_VIEW_STATUS_BAR
Command11=ID_APP_ABOUT
CommandCount=11

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_LOADSOURCESHAPE
Command3=ID_FILE_LOADSOURCELANDMARKS
Command4=ID_FILE_LOADTARGETSHAPE
Command5=ID_FILE_LOADTARGETLANDMARKS
Command6=ID_FILE_SAVE
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_FILE_PRINT
Command11=ID_APP_ABOUT
CommandCount=11

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
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

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
ControlCount=5
Control1=IDOK,button,1342373889
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Class=CAboutDlg

[DLG:IDD_INSUFFICIENTLANDMARKSDIALOG]
Type=1
Class=CInsufficientLandmarksDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:CInsufficientLandmarksDlg]
Type=0
HeaderFile=InsufficientLandmarksDlg.h
ImplementationFile=InsufficientLandmarksDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CInsufficientLandmarksDlg

