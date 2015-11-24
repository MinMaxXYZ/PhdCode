# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=BodyAnalyser - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to BodyAnalyser - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "BodyAnalyser - Win32 Release" && "$(CFG)" !=\
 "BodyAnalyser - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "BodyAnalyser.mak" CFG="BodyAnalyser - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BodyAnalyser - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "BodyAnalyser - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "BodyAnalyser - Win32 Debug"
CPP=cl.exe
MTL=mktyplib.exe
RSC=rc.exe

!IF  "$(CFG)" == "BodyAnalyser - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\BodyAnalyser.exe"

CLEAN : 
	-@erase "$(INTDIR)\BicubicSurf.obj"
	-@erase "$(INTDIR)\BiquadSurf.obj"
	-@erase "$(INTDIR)\BodyAnalyser.obj"
	-@erase "$(INTDIR)\BodyAnalyser.pch"
	-@erase "$(INTDIR)\BodyAnalyser.res"
	-@erase "$(INTDIR)\BodyAnalyserDoc.obj"
	-@erase "$(INTDIR)\BodyAnalyserView.obj"
	-@erase "$(INTDIR)\CameraImageFrame.obj"
	-@erase "$(INTDIR)\CamImage.obj"
	-@erase "$(INTDIR)\CannyParamsDialog.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ConfirmDialog.obj"
	-@erase "$(INTDIR)\CurvatureProfile.obj"
	-@erase "$(INTDIR)\CurvMapConfirmDialog.obj"
	-@erase "$(INTDIR)\DialogCameraImager.obj"
	-@erase "$(INTDIR)\DlgCurvatureProgress.obj"
	-@erase "$(INTDIR)\DlgCurvThresholds.obj"
	-@erase "$(INTDIR)\DlgEvaluation.obj"
	-@erase "$(INTDIR)\DlgEvaluationReport.obj"
	-@erase "$(INTDIR)\DlgHistogram.obj"
	-@erase "$(INTDIR)\DlgWrapMesh.obj"
	-@erase "$(INTDIR)\FloatMatrix.obj"
	-@erase "$(INTDIR)\Histogram.obj"
	-@erase "$(INTDIR)\LandmarkMapping.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\NoCurvMapDialog.obj"
	-@erase "$(INTDIR)\PointMesh.obj"
	-@erase "$(INTDIR)\pointset.obj"
	-@erase "$(INTDIR)\QuadricSurf.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\BodyAnalyser.exe"
	-@erase "$(OUTDIR)\BodyAnalyser.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W2 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /Gs64 /c
CPP_PROJ=/nologo /MD /W2 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/BodyAnalyser.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Gs64 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /i "d:\documents\code" /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x809 /fo"$(INTDIR)/BodyAnalyser.res" /i "d:\documents\code" /d\
 "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/BodyAnalyser.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/BodyAnalyser.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/BodyAnalyser.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BicubicSurf.obj" \
	"$(INTDIR)\BiquadSurf.obj" \
	"$(INTDIR)\BodyAnalyser.obj" \
	"$(INTDIR)\BodyAnalyser.res" \
	"$(INTDIR)\BodyAnalyserDoc.obj" \
	"$(INTDIR)\BodyAnalyserView.obj" \
	"$(INTDIR)\CameraImageFrame.obj" \
	"$(INTDIR)\CamImage.obj" \
	"$(INTDIR)\CannyParamsDialog.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\ConfirmDialog.obj" \
	"$(INTDIR)\CurvatureProfile.obj" \
	"$(INTDIR)\CurvMapConfirmDialog.obj" \
	"$(INTDIR)\DialogCameraImager.obj" \
	"$(INTDIR)\DlgCurvatureProgress.obj" \
	"$(INTDIR)\DlgCurvThresholds.obj" \
	"$(INTDIR)\DlgEvaluation.obj" \
	"$(INTDIR)\DlgEvaluationReport.obj" \
	"$(INTDIR)\DlgHistogram.obj" \
	"$(INTDIR)\DlgWrapMesh.obj" \
	"$(INTDIR)\FloatMatrix.obj" \
	"$(INTDIR)\Histogram.obj" \
	"$(INTDIR)\LandmarkMapping.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\NoCurvMapDialog.obj" \
	"$(INTDIR)\PointMesh.obj" \
	"$(INTDIR)\pointset.obj" \
	"$(INTDIR)\QuadricSurf.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\BodyAnalyser.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "BodyAnalyser - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\BodyAnalyser.exe"

CLEAN : 
	-@erase "$(INTDIR)\BicubicSurf.obj"
	-@erase "$(INTDIR)\BiquadSurf.obj"
	-@erase "$(INTDIR)\BodyAnalyser.obj"
	-@erase "$(INTDIR)\BodyAnalyser.pch"
	-@erase "$(INTDIR)\BodyAnalyser.res"
	-@erase "$(INTDIR)\BodyAnalyserDoc.obj"
	-@erase "$(INTDIR)\BodyAnalyserView.obj"
	-@erase "$(INTDIR)\CameraImageFrame.obj"
	-@erase "$(INTDIR)\CamImage.obj"
	-@erase "$(INTDIR)\CannyParamsDialog.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ConfirmDialog.obj"
	-@erase "$(INTDIR)\CurvatureProfile.obj"
	-@erase "$(INTDIR)\CurvMapConfirmDialog.obj"
	-@erase "$(INTDIR)\DialogCameraImager.obj"
	-@erase "$(INTDIR)\DlgCurvatureProgress.obj"
	-@erase "$(INTDIR)\DlgCurvThresholds.obj"
	-@erase "$(INTDIR)\DlgEvaluation.obj"
	-@erase "$(INTDIR)\DlgEvaluationReport.obj"
	-@erase "$(INTDIR)\DlgHistogram.obj"
	-@erase "$(INTDIR)\DlgWrapMesh.obj"
	-@erase "$(INTDIR)\FloatMatrix.obj"
	-@erase "$(INTDIR)\Histogram.obj"
	-@erase "$(INTDIR)\LandmarkMapping.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\NoCurvMapDialog.obj"
	-@erase "$(INTDIR)\PointMesh.obj"
	-@erase "$(INTDIR)\pointset.obj"
	-@erase "$(INTDIR)\QuadricSurf.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\BodyAnalyser.exe"
	-@erase "$(OUTDIR)\BodyAnalyser.ilk"
	-@erase "$(OUTDIR)\BodyAnalyser.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W2 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W2 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/BodyAnalyser.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /i "d:\documents\code" /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x809 /fo"$(INTDIR)/BodyAnalyser.res" /i "d:\documents\code" /d\
 "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/BodyAnalyser.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/BodyAnalyser.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/BodyAnalyser.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BicubicSurf.obj" \
	"$(INTDIR)\BiquadSurf.obj" \
	"$(INTDIR)\BodyAnalyser.obj" \
	"$(INTDIR)\BodyAnalyser.res" \
	"$(INTDIR)\BodyAnalyserDoc.obj" \
	"$(INTDIR)\BodyAnalyserView.obj" \
	"$(INTDIR)\CameraImageFrame.obj" \
	"$(INTDIR)\CamImage.obj" \
	"$(INTDIR)\CannyParamsDialog.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\ConfirmDialog.obj" \
	"$(INTDIR)\CurvatureProfile.obj" \
	"$(INTDIR)\CurvMapConfirmDialog.obj" \
	"$(INTDIR)\DialogCameraImager.obj" \
	"$(INTDIR)\DlgCurvatureProgress.obj" \
	"$(INTDIR)\DlgCurvThresholds.obj" \
	"$(INTDIR)\DlgEvaluation.obj" \
	"$(INTDIR)\DlgEvaluationReport.obj" \
	"$(INTDIR)\DlgHistogram.obj" \
	"$(INTDIR)\DlgWrapMesh.obj" \
	"$(INTDIR)\FloatMatrix.obj" \
	"$(INTDIR)\Histogram.obj" \
	"$(INTDIR)\LandmarkMapping.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\NoCurvMapDialog.obj" \
	"$(INTDIR)\PointMesh.obj" \
	"$(INTDIR)\pointset.obj" \
	"$(INTDIR)\QuadricSurf.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\BodyAnalyser.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "BodyAnalyser - Win32 Release"
# Name "BodyAnalyser - Win32 Debug"

!IF  "$(CFG)" == "BodyAnalyser - Win32 Release"

!ELSEIF  "$(CFG)" == "BodyAnalyser - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "BodyAnalyser - Win32 Release"

!ELSEIF  "$(CFG)" == "BodyAnalyser - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\BodyAnalyser.cpp
DEP_CPP_BODYA=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\BodyAnalyserDoc.h"\
	".\BodyAnalyserView.h"\
	".\ChildFrm.h"\
	".\CurvatureProfile.h"\
	".\Histogram.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\elements\SoDrawStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoInt32Element.h"\
	{$(INCLUDE)}"\Inventor\elements\SoLazyElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoMaterialBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoSubElement.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFColor.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFUShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\misc\SoState.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLightModel.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbColor.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\Ivf\IvfMainfrm.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfRenderArea.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\BodyAnalyser.obj" : $(SOURCE) $(DEP_CPP_BODYA) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "BodyAnalyser - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W2 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/BodyAnalyser.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Gs64 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\BodyAnalyser.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "BodyAnalyser - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W2 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/BodyAnalyser.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\BodyAnalyser.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\BodyAnalyserView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\Ivf\IvfMainfrm.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\ChildFrm.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\BodyAnalyserDoc.cpp

!IF  "$(CFG)" == "BodyAnalyser - Win32 Release"

DEP_CPP_BODYAN=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\BodyAnalyserDoc.h"\
	".\BodyAnalyserView.h"\
	".\CameraImageFrame.h"\
	".\CannyParamsDialog.h"\
	".\ConfirmDialog.h"\
	".\CurvatureProfile.h"\
	".\CurvMapConfirmDialog.h"\
	".\DialogCameraImager.h"\
	".\DlgCurvatureProgress.h"\
	".\dlgcurvthresholds.h"\
	".\DlgEvaluation.h"\
	".\DlgEvaluationReport.h"\
	".\DlgHistogram.h"\
	".\DlgWrapMesh.h"\
	".\Histogram.h"\
	".\NoCurvMapDialog.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\bicubicsurf.h"\
	{$(INCLUDE)}"\biquadsurf.h"\
	{$(INCLUDE)}"\FloatMatrix.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\elements\SoComplexityTypeElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoDrawStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoGLShapeHintsElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoInt32Element.h"\
	{$(INCLUDE)}"\Inventor\elements\SoLazyElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoMaterialBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoNormalBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoReplacedElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoShapeHintsElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoShapeStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoSubElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoTextureCoordinateBindingElement.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFColor.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFUInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec2f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBitMask.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFNode.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFUShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\misc\SoState.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoBaseColor.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoComplexity.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoCone.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoCoordinate3.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoFaceSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoIndexedFaceSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLightModel.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLineSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNonIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormal.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormalBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsCurve.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsSurface.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoPointSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoQuadMesh.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSeparator.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoShapeHints.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSphere.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoTextureCoordinateBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoTransformation.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoTranslation.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexProperty.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexShape.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbColor.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\LandmarkMapping.h"\
	{$(INCLUDE)}"\MathTools.h"\
	{$(INCLUDE)}"\PointMesh.h"\
	{$(INCLUDE)}"\PointSet.h"\
	{$(INCLUDE)}"\QuadricSurf.h"\
	{$(INCLUDE)}"\recipes.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\BodyAnalyserDoc.obj" : $(SOURCE) $(DEP_CPP_BODYAN) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


!ELSEIF  "$(CFG)" == "BodyAnalyser - Win32 Debug"

DEP_CPP_BODYAN=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\BodyAnalyserDoc.h"\
	".\BodyAnalyserView.h"\
	".\CameraImageFrame.h"\
	".\CannyParamsDialog.h"\
	".\ConfirmDialog.h"\
	".\CurvatureProfile.h"\
	".\CurvMapConfirmDialog.h"\
	".\DialogCameraImager.h"\
	".\DlgCurvatureProgress.h"\
	".\dlgcurvthresholds.h"\
	".\DlgEvaluation.h"\
	".\DlgEvaluationReport.h"\
	".\DlgHistogram.h"\
	".\DlgWrapMesh.h"\
	".\Histogram.h"\
	".\NoCurvMapDialog.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\bicubicsurf.h"\
	{$(INCLUDE)}"\biquadsurf.h"\
	{$(INCLUDE)}"\FloatMatrix.h"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\elements\SoComplexityTypeElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoGLShapeHintsElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoInt32Element.h"\
	{$(INCLUDE)}"\Inventor\elements\SoReplacedElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoShapeHintsElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoSubElement.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFColor.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBitMask.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\misc\SoState.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoBaseColor.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoComplexity.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoCone.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoCoordinate3.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoFaceSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoIndexedFaceSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLineSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNonIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormal.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsCurve.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsSurface.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoPointSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoQuadMesh.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSeparator.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoShapeHints.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSphere.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoTransformation.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoTranslation.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexShape.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbColor.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\LandmarkMapping.h"\
	{$(INCLUDE)}"\MathTools.h"\
	{$(INCLUDE)}"\PointMesh.h"\
	{$(INCLUDE)}"\PointSet.h"\
	{$(INCLUDE)}"\QuadricSurf.h"\
	{$(INCLUDE)}"\recipes.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\BodyAnalyserDoc.obj" : $(SOURCE) $(DEP_CPP_BODYAN) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\BodyAnalyserView.cpp
DEP_CPP_BODYANA=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\BodyAnalyserDoc.h"\
	".\BodyAnalyserView.h"\
	".\CurvatureProfile.h"\
	".\Histogram.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\elements\SoDrawStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoInt32Element.h"\
	{$(INCLUDE)}"\Inventor\elements\SoLazyElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoMaterialBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoSubElement.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFColor.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFUShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\misc\SoState.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLightModel.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbColor.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\BodyAnalyserView.obj" : $(SOURCE) $(DEP_CPP_BODYANA) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\BodyAnalyser.rc
DEP_RSC_BODYANAL=\
	".\res\bitmap1.bmp"\
	".\res\BodyAnalyser.ico"\
	".\res\BodyAnalyser.rc2"\
	".\res\BodyAnalyserDoc.ico"\
	".\res\Toolbar.bmp"\
	".\resource.hm"\
	

"$(INTDIR)\BodyAnalyser.res" : $(SOURCE) $(DEP_RSC_BODYANAL) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DialogCameraImager.cpp
DEP_CPP_DIALO=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\DialogCameraImager.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\DialogCameraImager.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CamImage.cpp
DEP_CPP_CAMIM=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\CamImage.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\CamImage.obj" : $(SOURCE) $(DEP_CPP_CAMIM) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CameraImageFrame.cpp
DEP_CPP_CAMER=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\CameraImageFrame.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\CameraImageFrame.obj" : $(SOURCE) $(DEP_CPP_CAMER) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\PhD\Code\bldefs.h

!IF  "$(CFG)" == "BodyAnalyser - Win32 Release"

!ELSEIF  "$(CFG)" == "BodyAnalyser - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ConfirmDialog.cpp
DEP_CPP_CONFI=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\ConfirmDialog.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\ConfirmDialog.obj" : $(SOURCE) $(DEP_CPP_CONFI) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CurvatureProfile.cpp
DEP_CPP_CURVA=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\CurvatureProfile.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\CurvatureProfile.obj" : $(SOURCE) $(DEP_CPP_CURVA) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\NoCurvMapDialog.cpp
DEP_CPP_NOCUR=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\NoCurvMapDialog.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\NoCurvMapDialog.obj" : $(SOURCE) $(DEP_CPP_NOCUR) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\pointset.cpp
DEP_CPP_POINT=\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\elements\SoComplexityTypeElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoDrawStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoInt32Element.h"\
	{$(INCLUDE)}"\Inventor\elements\SoLazyElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoMaterialBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoNormalBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoShapeStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoSubElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoTextureCoordinateBindingElement.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFColor.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFUInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec2f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBitMask.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFNode.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFUShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\misc\SoState.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoComplexity.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoCoordinate3.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLineSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNonIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormalBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsCurve.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsSurface.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoPointSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSeparator.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoTextureCoordinateBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexProperty.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexShape.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbColor.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\PointSet.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_POINT=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\pointset.obj" : $(SOURCE) $(DEP_CPP_POINT) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\FloatMatrix.cpp
DEP_CPP_FLOAT=\
	{$(INCLUDE)}"\FloatMatrix.h"\
	
NODEP_CPP_FLOAT=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\FloatMatrix.obj" : $(SOURCE) $(DEP_CPP_FLOAT) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\LandmarkMapping.cpp
DEP_CPP_LANDM=\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\elements\SoComplexityTypeElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoDrawStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoInt32Element.h"\
	{$(INCLUDE)}"\Inventor\elements\SoLazyElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoMaterialBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoNormalBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoShapeStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoSubElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoTextureCoordinateBindingElement.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFColor.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFUInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec2f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBitMask.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFNode.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFUShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\misc\SoState.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoComplexity.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoCoordinate3.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLineSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNonIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormalBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsCurve.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsSurface.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoPointSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSeparator.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoTextureCoordinateBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexProperty.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexShape.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbColor.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\LandmarkMapping.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_LANDM=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\LandmarkMapping.obj" : $(SOURCE) $(DEP_CPP_LANDM) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\PointMesh.cpp
DEP_CPP_POINTM=\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\elements\SoComplexityTypeElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoDrawStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoGLShapeHintsElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoInt32Element.h"\
	{$(INCLUDE)}"\Inventor\elements\SoLazyElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoMaterialBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoNormalBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoReplacedElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoShapeHintsElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoShapeStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoSubElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoTextureCoordinateBindingElement.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFColor.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFUInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec2f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBitMask.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFNode.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFUShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\misc\SoState.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoComplexity.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoCoordinate3.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLineSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNonIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormalBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsCurve.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNurbsSurface.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoPointSet.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoQuadMesh.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSeparator.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoShapeHints.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoTextureCoordinateBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexProperty.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoVertexShape.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbColor.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\PointMesh.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_POINTM=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\PointMesh.obj" : $(SOURCE) $(DEP_CPP_POINTM) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\BiquadSurf.cpp
DEP_CPP_BIQUA=\
	{$(INCLUDE)}"\biquadsurf.h"\
	
NODEP_CPP_BIQUA=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\BiquadSurf.obj" : $(SOURCE) $(DEP_CPP_BIQUA) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CurvMapConfirmDialog.cpp
DEP_CPP_CURVM=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\CurvMapConfirmDialog.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\CurvMapConfirmDialog.obj" : $(SOURCE) $(DEP_CPP_CURVM) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\BicubicSurf.cpp
DEP_CPP_BICUB=\
	{$(INCLUDE)}"\bicubicsurf.h"\
	{$(INCLUDE)}"\biquadsurf.h"\
	
NODEP_CPP_BICUB=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\BicubicSurf.obj" : $(SOURCE) $(DEP_CPP_BICUB) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CannyParamsDialog.cpp
DEP_CPP_CANNY=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\CannyParamsDialog.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\CannyParamsDialog.obj" : $(SOURCE) $(DEP_CPP_CANNY) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\QuadricSurf.cpp
DEP_CPP_QUADR=\
	{$(INCLUDE)}"\QuadricSurf.h"\
	
NODEP_CPP_QUADR=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\QuadricSurf.obj" : $(SOURCE) $(DEP_CPP_QUADR) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DlgCurvatureProgress.cpp
DEP_CPP_DLGCU=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\DlgCurvatureProgress.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\DlgCurvatureProgress.obj" : $(SOURCE) $(DEP_CPP_DLGCU) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Histogram.cpp
DEP_CPP_HISTO=\
	".\Histogram.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Histogram.obj" : $(SOURCE) $(DEP_CPP_HISTO) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DlgHistogram.cpp
DEP_CPP_DLGHI=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\BodyAnalyserDoc.h"\
	".\CurvatureProfile.h"\
	".\DlgHistogram.h"\
	".\Histogram.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\elements\SoDrawStyleElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoInt32Element.h"\
	{$(INCLUDE)}"\Inventor\elements\SoLazyElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoMaterialBindingElement.h"\
	{$(INCLUDE)}"\Inventor\elements\SoSubElement.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFColor.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFVec3f.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFUShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\misc\SoState.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoLightModel.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbColor.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\DlgHistogram.obj" : $(SOURCE) $(DEP_CPP_DLGHI) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DlgCurvThresholds.cpp
DEP_CPP_DLGCUR=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\dlgcurvthresholds.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\DlgCurvThresholds.obj" : $(SOURCE) $(DEP_CPP_DLGCUR) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DlgEvaluation.cpp
DEP_CPP_DLGEV=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\DlgEvaluation.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\DlgEvaluation.obj" : $(SOURCE) $(DEP_CPP_DLGEV) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DlgEvaluationReport.cpp
DEP_CPP_DLGEVA=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\DlgEvaluationReport.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\DlgEvaluationReport.obj" : $(SOURCE) $(DEP_CPP_DLGEVA) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DlgWrapMesh.cpp
DEP_CPP_DLGWR=\
	"..\bldefs.h"\
	".\BodyAnalyser.h"\
	".\DlgWrapMesh.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\DlgWrapMesh.obj" : $(SOURCE) $(DEP_CPP_DLGWR) "$(INTDIR)"\
 "$(INTDIR)\BodyAnalyser.pch"


# End Source File
# End Target
# End Project
################################################################################
