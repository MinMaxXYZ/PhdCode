# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=IVAnimator - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to IVAnimator - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "IVAnimator - Win32 Release" && "$(CFG)" !=\
 "IVAnimator - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "IVAnimator.mak" CFG="IVAnimator - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IVAnimator - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "IVAnimator - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "IVAnimator - Win32 Debug"
CPP=cl.exe
MTL=mktyplib.exe
RSC=rc.exe

!IF  "$(CFG)" == "IVAnimator - Win32 Release"

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

ALL : "$(OUTDIR)\IVAnimator.exe"

CLEAN : 
	-@erase "$(INTDIR)\DlgMovieController.obj"
	-@erase "$(INTDIR)\IVAnimator.obj"
	-@erase "$(INTDIR)\IVAnimator.pch"
	-@erase "$(INTDIR)\IVAnimator.res"
	-@erase "$(INTDIR)\IVAnimatorDoc.obj"
	-@erase "$(INTDIR)\IVAnimatorView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\IVAnimator.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/IVAnimator.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x809 /fo"$(INTDIR)/IVAnimator.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/IVAnimator.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/IVAnimator.pdb" /machine:I386 /out:"$(OUTDIR)/IVAnimator.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DlgMovieController.obj" \
	"$(INTDIR)\IVAnimator.obj" \
	"$(INTDIR)\IVAnimator.res" \
	"$(INTDIR)\IVAnimatorDoc.obj" \
	"$(INTDIR)\IVAnimatorView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\IVAnimator.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IVAnimator - Win32 Debug"

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

ALL : "$(OUTDIR)\IVAnimator.exe"

CLEAN : 
	-@erase "$(INTDIR)\DlgMovieController.obj"
	-@erase "$(INTDIR)\IVAnimator.obj"
	-@erase "$(INTDIR)\IVAnimator.pch"
	-@erase "$(INTDIR)\IVAnimator.res"
	-@erase "$(INTDIR)\IVAnimatorDoc.obj"
	-@erase "$(INTDIR)\IVAnimatorView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\IVAnimator.exe"
	-@erase "$(OUTDIR)\IVAnimator.ilk"
	-@erase "$(OUTDIR)\IVAnimator.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/IVAnimator.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x809 /fo"$(INTDIR)/IVAnimator.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/IVAnimator.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/IVAnimator.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/IVAnimator.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DlgMovieController.obj" \
	"$(INTDIR)\IVAnimator.obj" \
	"$(INTDIR)\IVAnimator.res" \
	"$(INTDIR)\IVAnimatorDoc.obj" \
	"$(INTDIR)\IVAnimatorView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\IVAnimator.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "IVAnimator - Win32 Release"
# Name "IVAnimator - Win32 Debug"

!IF  "$(CFG)" == "IVAnimator - Win32 Release"

!ELSEIF  "$(CFG)" == "IVAnimator - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "IVAnimator - Win32 Release"

!ELSEIF  "$(CFG)" == "IVAnimator - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\IVAnimator.cpp

!IF  "$(CFG)" == "IVAnimator - Win32 Release"

DEP_CPP_IVANI=\
	".\IVAnimator.h"\
	".\IVAnimatorDoc.h"\
	".\IVAnimatorView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfEnterScope.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoChildList.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoFile.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfMainfrm.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfRenderArea.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\IVAnimator.obj" : $(SOURCE) $(DEP_CPP_IVANI) "$(INTDIR)"\
 "$(INTDIR)\IVAnimator.pch"


!ELSEIF  "$(CFG)" == "IVAnimator - Win32 Debug"

DEP_CPP_IVANI=\
	".\IVAnimator.h"\
	".\IVAnimatorDoc.h"\
	".\IVAnimatorView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfEnterScope.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\engines\SoEngine.h"\
	{$(INCLUDE)}"\Inventor\engines\SoOutputData.h"\
	{$(INCLUDE)}"\Inventor\engines\SoSubEngine.h"\
	{$(INCLUDE)}"\Inventor\engines\SoTimeCounter.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBitMask.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBool.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFString.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFTime.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFTrigger.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoChildList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoBlinker.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoFile.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSeparator.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSwitch.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoDelayQueueSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoOneShotSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfMainfrm.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfRenderArea.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\IVAnimator.obj" : $(SOURCE) $(DEP_CPP_IVANI) "$(INTDIR)"\
 "$(INTDIR)\IVAnimator.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "IVAnimator - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/IVAnimator.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\IVAnimator.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "IVAnimator - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/IVAnimator.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\IVAnimator.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\IVAnimator.h"\
	".\IVAnimatorView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfEnterScope.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\IvfMainfrm.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\IVAnimator.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\IVAnimatorDoc.cpp
DEP_CPP_IVANIM=\
	".\DlgMovieController.h"\
	".\IVAnimator.h"\
	".\IVAnimatorDoc.h"\
	".\IVAnimatorView.h"\
	".\StdAfx.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfEnterScope.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\engines\SoEngine.h"\
	{$(INCLUDE)}"\Inventor\engines\SoOutputData.h"\
	{$(INCLUDE)}"\Inventor\engines\SoSubEngine.h"\
	{$(INCLUDE)}"\Inventor\engines\SoTimeCounter.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBitMask.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBool.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFString.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFTime.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFTrigger.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoChildList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoBlinker.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoFile.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSeparator.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSwitch.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoDelayQueueSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoOneShotSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\IVAnimatorDoc.obj" : $(SOURCE) $(DEP_CPP_IVANIM) "$(INTDIR)"\
 "$(INTDIR)\IVAnimator.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\IVAnimatorView.cpp
DEP_CPP_IVANIMA=\
	".\IVAnimator.h"\
	".\IVAnimatorDoc.h"\
	".\IVAnimatorView.h"\
	".\StdAfx.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfEnterScope.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\IVAnimatorView.obj" : $(SOURCE) $(DEP_CPP_IVANIMA) "$(INTDIR)"\
 "$(INTDIR)\IVAnimator.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\IVAnimator.rc
DEP_RSC_IVANIMAT=\
	".\res\IVAnimator.ico"\
	".\res\IVAnimator.rc2"\
	".\res\IVAnimatorDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\IVAnimator.res" : $(SOURCE) $(DEP_RSC_IVANIMAT) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DlgMovieController.cpp
DEP_CPP_DLGMO=\
	".\DlgMovieController.h"\
	".\IVAnimator.h"\
	".\IVAnimatorDoc.h"\
	".\StdAfx.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfEnterScope.h"\
	"C:\TGSOIV2.2.1\include\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\inttypes.h"\
	{$(INCLUDE)}"\Inventor\engines\SoEngine.h"\
	{$(INCLUDE)}"\Inventor\engines\SoOutputData.h"\
	{$(INCLUDE)}"\Inventor\engines\SoSubEngine.h"\
	{$(INCLUDE)}"\Inventor\engines\SoTimeCounter.h"\
	{$(INCLUDE)}"\Inventor\errors\SoDebugError.h"\
	{$(INCLUDE)}"\Inventor\errors\SoError.h"\
	{$(INCLUDE)}"\Inventor\fields\SoField.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldContainer.h"\
	{$(INCLUDE)}"\Inventor\fields\SoFieldData.h"\
	{$(INCLUDE)}"\Inventor\fields\SoMFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBitMask.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFBool.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFEnum.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFFloat.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFInt32.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFShort.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFString.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFTime.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSFTrigger.h"\
	{$(INCLUDE)}"\Inventor\fields\SoSubField.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Inventor\misc\SoAuditorList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBase.h"\
	{$(INCLUDE)}"\Inventor\misc\SoBasic.h"\
	{$(INCLUDE)}"\Inventor\misc\SoChildList.h"\
	{$(INCLUDE)}"\Inventor\misc\SoNotification.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoBlinker.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoFile.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSeparator.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSubNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoSwitch.h"\
	{$(INCLUDE)}"\Inventor\non_winsys.h"\
	{$(INCLUDE)}"\Inventor\oivwin32.h"\
	{$(INCLUDE)}"\Inventor\SbBasic.h"\
	{$(INCLUDE)}"\Inventor\SbDict.h"\
	{$(INCLUDE)}"\Inventor\SbLinear.h"\
	{$(INCLUDE)}"\Inventor\SbPList.h"\
	{$(INCLUDE)}"\Inventor\SbString.h"\
	{$(INCLUDE)}"\Inventor\SbTime.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoDelayQueueSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoOneShotSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensor.h"\
	{$(INCLUDE)}"\Inventor\sensors\SoSensorManager.h"\
	{$(INCLUDE)}"\Inventor\SoDB.h"\
	{$(INCLUDE)}"\Inventor\SoInput.h"\
	{$(INCLUDE)}"\Inventor\SoLists.h"\
	{$(INCLUDE)}"\Inventor\SoOutput.h"\
	{$(INCLUDE)}"\Inventor\SoType.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfComponent.h"\
	{$(INCLUDE)}"\Ivf\IvfDocument.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\DlgMovieController.obj" : $(SOURCE) $(DEP_CPP_DLGMO) "$(INTDIR)"\
 "$(INTDIR)\IVAnimator.pch"


# End Source File
# End Target
# End Project
################################################################################
