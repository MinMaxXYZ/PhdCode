; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgEvaluationReport
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BodyAnalyser.h"
LastPage=0

ClassCount=22
Class1=CBodyAnalyserApp
Class2=CBodyAnalyserDoc
Class3=CBodyAnalyserView
Class4=CMainFrame

ResourceCount=17
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_BODYANTYPE
Class5=CAboutDlg
Class6=CChildFrame
Resource4=IDD_NOCURVMAP
Resource5=IDD_HISTOGRAM
Resource6=IDD_CAMERA_IMAGER
Class7=CDialogCameraImager
Class8=CCamImage
Class9=CCameraImageFrame
Resource7=IDD_ABOUTBOX (English (U.S.))
Class10=CConfirmDialog
Resource8=IDD_BSS_CONFIRM
Class11=CCurvatureProfile
Class12=CNoCurvMapDialog
Resource9=IDD_CURVMAP_CONFIRM
Class13=CCurvMapConfirmDialog
Resource10=IDD_CURVATURE_PROGRESS
Class14=CCannyParamsDialog
Resource11=IDD_CANNY_PARAMS
Class15=CDlgCurvatureProgress
Resource12=IDR_BODYANTYPE (English (U.S.))
Class16=CHistogram
Class17=CDlgHistogram
Resource13=IDR_MAINFRAME (English (U.S.))
Class18=DlgCurvThresholds
Resource14=IDD_EVALUATION_REPORT
Class19=CDlgCurvThresholds
Class20=CDlgEvaluation
Resource15=IDD_EVALUATION
Class21=CDlgEvaluationReport
Resource16=IDD_HYST_THRESHOLDS
Class22=CDlgWrapMesh
Resource17=IDD_WRAP_MESH

[CLS:CBodyAnalyserApp]
Type=0
HeaderFile=BodyAnalyser.h
ImplementationFile=BodyAnalyser.cpp
Filter=N

[CLS:CBodyAnalyserDoc]
Type=0
HeaderFile=BodyAnalyserDoc.h
ImplementationFile=BodyAnalyserDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=IDC_UTHRES

[CLS:CBodyAnalyserView]
Type=0
HeaderFile=BodyAnalyserView.h
ImplementationFile=BodyAnalyserView.cpp
Filter=C
LastObject=ID_VIEW_SYMMETRYPLANES_NONE

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
LastObject=CChildFrame

[CLS:CAboutDlg]
Type=0
HeaderFile=BodyAnalyser.cpp
ImplementationFile=BodyAnalyser.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_ABOUT_TEXT,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_BODYANTYPE]
Type=1
Class=CBodyAnalyserView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_RELOAD
Command4=ID_FILE_IMPORT
Command5=ID_FILE_CLOSE
Command6=ID_FILE_SAVE
Command7=ID_FILE_SAVE_AS
Command8=ID_FILE_PRINT
Command9=ID_FILE_PRINT_PREVIEW
Command10=ID_FILE_PRINT_SETUP
Command11=ID_FILE_INFO
Command12=ID_APP_EXIT
Command13=ID_EDIT_UNDO
Command14=ID_EDIT_CUT
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_VIEW_TOOLBAR
Command18=ID_VIEW_STATUS_BAR
Command19=ID_VIEW_POINTCLOUD
Command20=ID_VIEW_CONNECTEDMESH_CAMERA0
Command21=ID_VIEW_CONNECTEDMESH_CAMERA1
Command22=ID_VIEW_CONNECTEDMESH_CAMERA2
Command23=ID_VIEW_CONNECTEDMESH_CAMERA3
Command24=ID_VIEW_CONNECTEDMESH_CAMERA4
Command25=ID_VIEW_CONNECTEDMESH_CAMERA5
Command26=ID_VIEW_CONNECTEDMESH_CAMERA6
Command27=ID_VIEW_CONNECTEDMESH_CAMERA7
Command28=ID_VIEW_CONNECTEDMESH_ALL
Command29=ID_VIEW_CONNECTEDMESH_NONE
Command30=ID_VIEW_REFERENCEFRAME
Command31=ID_VIEW_COORDINATEORIGIN
Command32=ID_VIEW_PICEDIT
Command33=ID_WINDOW_NEW
Command34=ID_WINDOW_CASCADE
Command35=ID_WINDOW_TILE_HORZ
Command36=ID_WINDOW_ARRANGE
Command37=IDM_VIEWPOINTS
Command38=ID_APP_ABOUT
CommandCount=38

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

[MNU:IDR_BODYANTYPE (English (U.S.))]
Type=1
Class=CBodyAnalyserView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_RELOAD
Command4=ID_FILE_IMPORT
Command5=ID_FILE_CLOSE
Command6=ID_FILE_SAVE
Command7=ID_FILE_SAVE_AS
Command8=ID_FILE_PRINT
Command9=ID_FILE_PRINT_PREVIEW
Command10=ID_FILE_PRINT_SETUP
Command11=ID_FILE_INFO
Command12=ID_APP_EXIT
Command13=ID_EDIT_UNDO
Command14=ID_EDIT_CUT
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_VIEW_TOOLBAR
Command18=ID_VIEW_STATUS_BAR
Command19=ID_VIEW_POINTCLOUD
Command20=ID_VIEW_OUTLIERCLOUD
Command21=ID_VIEW_REFERENCEFRAME
Command22=ID_VIEW_COORDINATEORIGIN
Command23=ID_VIEW_SYMMETRYPLANES_BODY
Command24=ID_VIEW_SYMMETRYPLANES_ELLIPSOID
Command25=ID_VIEW_SYMMETRYPLANES_TOOTHCUBE
Command26=ID_VIEW_SYMMETRYPLANES_OCTAHEDRONDIAMOND
Command27=ID_VIEW_SYMMETRYPLANES_BUMPYSPHERETETRAHEDRON
Command28=ID_VIEW_SYMMETRYPLANES_NONE
Command29=ID_VIEW_CONNECTEDMESH_CAMERA0
Command30=ID_VIEW_CONNECTEDMESH_CAMERA1
Command31=ID_VIEW_CONNECTEDMESH_CAMERA2
Command32=ID_VIEW_CONNECTEDMESH_CAMERA3
Command33=ID_VIEW_CONNECTEDMESH_CAMERA4
Command34=ID_VIEW_CONNECTEDMESH_CAMERA5
Command35=ID_VIEW_CONNECTEDMESH_CAMERA6
Command36=ID_VIEW_CONNECTEDMESH_CAMERA7
Command37=ID_VIEW_CONNECTEDMESH_ALL
Command38=ID_VIEW_CONNECTEDMESH_NONE
Command39=ID_VIEW_CONNECTEDMESH_PHOTOREALISTIC
Command40=ID_VIEW_COLOURMAP_N
Command41=ID_VIEW_COLOURMAP_INTENSITIES
Command42=ID_VIEW_COLOURMAP_GAUSSIANCURVATURE
Command43=ID_VIEW_COLOURMAP_MEANCURVATURE
Command44=ID_VIEW_COLOURMAP_CURVEDNESS
Command45=ID_VIEW_COLOURMAP_SHAPEINDEX
Command46=ID_VIEW_CONNECTEDMESH_TEXTUREEDGELS
Command47=ID_VIEW_CURVATUREDIRECTIONS_BLUE
Command48=ID_VIEW_CURVATUREDIRECTIONS_RED
Command49=ID_VIEW_CURVATUREDIRECTIONS
Command50=ID_VIEW_CURVATUREDIRECTIONS_ALL
Command51=ID_VIEW_CURVATUREDIRECTIONS_NONE
Command52=ID_VIEW_RIDGES
Command53=ID_VIEW_FLEXCORDS
Command54=ID_VIEW_PICEDIT
Command55=ID_TOOLS_SURFACESMOOTHING
Command56=ID_TOOLS_CURVATUREMAP_EXPORTCOVARIANCES
Command57=ID_TOOLS_CURVATUREMAP_CALCULATEFOCALSURFACES
Command58=ID_TOOLS_CURVATUREMAP_DETECTUMBILICPOINTS
Command59=ID_TOOLS_CURVATUREMAP_DETECTRIDGES
Command60=ID_TOOLS_HISTOGRAMEQUALISATION
Command61=ID_TOOLS_TEXTUREEDGEDETECTOR
Command62=ID_TOOLS_CAMERAIMAGER
Command63=ID_WINDOW_NEW
Command64=ID_WINDOW_CASCADE
Command65=ID_WINDOW_TILE_HORZ
Command66=ID_WINDOW_ARRANGE
Command67=IDM_VIEWPOINTS
Command68=ID_APP_ABOUT
CommandCount=68

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
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Command1=ID_VIEW_CONNECTEDMESH_ALL
Command2=ID_VIEW_CURVATUREDIRECTIONS_BLUE
Command3=ID_EDIT_COPY
Command4=ID_TOOLS_CURVATUREMAP_EXPORTCOVARIANCES
Command5=ID_FILE_NEW
Command6=ID_VIEW_CONNECTEDMESH_NONE
Command7=ID_FILE_OPEN
Command8=ID_FILE_PRINT
Command9=ID_VIEW_CONNECTEDMESH_PHOTOREALISTIC
Command10=ID_VIEW_CURVATUREDIRECTIONS_RED
Command11=ID_FILE_SAVE
Command12=ID_TOOLS_SURFACESMOOTHING
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_UNDO
Command15=ID_EDIT_CUT
Command16=ID_NEXT_PANE
Command17=ID_PREV_PANE
Command18=ID_EDIT_COPY
Command19=ID_EDIT_PASTE
Command20=ID_EDIT_CUT
Command21=ID_EDIT_UNDO
CommandCount=21

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_ABOUT_TEXT,static,1342308352

[CLS:CDialogCameraImager]
Type=0
HeaderFile=DialogCameraImager.h
ImplementationFile=DialogCameraImager.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CAMERA_0
VirtualFilter=dWC

[CLS:CCamImage]
Type=0
HeaderFile=CamImage.h
ImplementationFile=CamImage.cpp
BaseClass=CStatic
Filter=W
LastObject=CCamImage

[DLG:IDD_CAMERA_IMAGER]
Type=1
Class=CDialogCameraImager
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CAMERA_0,static,1342177294

[CLS:CCameraImageFrame]
Type=0
HeaderFile=CameraImageFrame.h
ImplementationFile=CameraImageFrame.cpp
BaseClass=CFrameWnd
Filter=T
LastObject=CCameraImageFrame
VirtualFilter=fWC

[DLG:IDD_BSS_CONFIRM]
Type=1
Class=CConfirmDialog
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CConfirmDialog]
Type=0
HeaderFile=ConfirmDialog.h
ImplementationFile=ConfirmDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfirmDialog

[CLS:CCurvatureProfile]
Type=0
HeaderFile=CurvatureProfile.h
ImplementationFile=CurvatureProfile.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CCurvatureProfile

[DLG:IDD_NOCURVMAP]
Type=1
Class=CNoCurvMapDialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:CNoCurvMapDialog]
Type=0
HeaderFile=NoCurvMapDialog.h
ImplementationFile=NoCurvMapDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CNoCurvMapDialog

[DLG:IDD_CURVMAP_CONFIRM]
Type=1
Class=CCurvMapConfirmDialog
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CCurvMapConfirmDialog]
Type=0
HeaderFile=CurvMapConfirmDialog.h
ImplementationFile=CurvMapConfirmDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CCurvMapConfirmDialog

[DLG:IDD_CANNY_PARAMS]
Type=1
Class=CCannyParamsDialog
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_MASKSIZE,edit,1350631552
Control5=IDC_UPPER_THRESHOLD,edit,1350631552
Control6=IDC_LOWER_THRESHOLD,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352

[CLS:CCannyParamsDialog]
Type=0
HeaderFile=CannyParamsDialog.h
ImplementationFile=CannyParamsDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_MASKSIZE
VirtualFilter=dWC

[DLG:IDD_CURVATURE_PROGRESS]
Type=1
Class=CDlgCurvatureProgress
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308353
Control3=IDC_STATIC,static,1342308353

[CLS:CDlgCurvatureProgress]
Type=0
HeaderFile=DlgCurvatureProgress.h
ImplementationFile=DlgCurvatureProgress.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgCurvatureProgress

[CLS:CHistogram]
Type=0
HeaderFile=Histogram.h
ImplementationFile=Histogram.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CHistogram

[DLG:IDD_HISTOGRAM]
Type=1
Class=CDlgHistogram
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlgHistogram]
Type=0
HeaderFile=DlgHistogram.h
ImplementationFile=DlgHistogram.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgHistogram
VirtualFilter=dWC

[DLG:IDD_HYST_THRESHOLDS]
Type=1
Class=CDlgCurvThresholds
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_LTHRES,edit,1350631552
Control3=IDC_HTHRES,edit,1350631552
Control4=IDC_STATIC,static,1342308354
Control5=IDC_STATIC,static,1342308354
Control6=IDC_MINRIDGES,button,1342242819

[CLS:DlgCurvThresholds]
Type=0
HeaderFile=DlgCurvThresholds.h
ImplementationFile=DlgCurvThresholds.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_HTHRES
VirtualFilter=dWC

[CLS:CDlgCurvThresholds]
Type=0
HeaderFile=dlgcurvthresholds.h
ImplementationFile=dlgcurvthresholds.cpp
BaseClass=CDialog
LastObject=CDlgCurvThresholds
Filter=D
VirtualFilter=dWC

[CLS:CDlgEvaluation]
Type=0
HeaderFile=DlgEvaluation.h
ImplementationFile=DlgEvaluation.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LTHR
VirtualFilter=dWC

[DLG:IDD_EVALUATION]
Type=1
Class=CDlgEvaluation
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SYMM_TYPE,combobox,1344339971
Control5=IDC_DTHR,edit,1350631552
Control6=IDC_STATIC,static,1342308354

[DLG:IDD_EVALUATION_REPORT]
Type=1
Class=CDlgEvaluationReport
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDC_LTHR,edit,1350633600
Control3=IDC_STATIC,static,1342308354
Control4=IDC_HTHR,edit,1350633600
Control5=IDC_STATIC,static,1342308354
Control6=IDC_DTHR,edit,1350633600
Control7=IDC_STATIC,static,1342308354
Control8=IDC_TRUEPOSITIVES,edit,1350633600
Control9=IDC_STATIC,static,1342308354
Control10=IDC_FALSEPOSITIVES,edit,1350633600
Control11=IDC_STATIC,static,1342308354
Control12=IDC_ALLPOSITIVES,edit,1350633600
Control13=IDC_STATIC,static,1342308354

[CLS:CDlgEvaluationReport]
Type=0
HeaderFile=DlgEvaluationReport.h
ImplementationFile=DlgEvaluationReport.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ALLPOSITIVES

[DLG:IDD_WRAP_MESH]
Type=1
Class=CDlgWrapMesh
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CDlgWrapMesh]
Type=0
HeaderFile=DlgWrapMesh.h
ImplementationFile=DlgWrapMesh.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgWrapMesh

