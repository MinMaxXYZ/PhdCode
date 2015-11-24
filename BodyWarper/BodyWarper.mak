# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=BodyWarper - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to BodyWarper - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "BodyWarper - Win32 Release" && "$(CFG)" !=\
 "BodyWarper - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "BodyWarper.mak" CFG="BodyWarper - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BodyWarper - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "BodyWarper - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "BodyWarper - Win32 Debug"
CPP=cl.exe
MTL=mktyplib.exe
RSC=rc.exe

!IF  "$(CFG)" == "BodyWarper - Win32 Release"

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

ALL : "$(OUTDIR)\BodyWarper.exe"

CLEAN : 
	-@erase "$(INTDIR)\BicubicSurf.obj"
	-@erase "$(INTDIR)\biquadsurf.obj"
	-@erase "$(INTDIR)\BodyWarper.obj"
	-@erase "$(INTDIR)\BodyWarper.pch"
	-@erase "$(INTDIR)\BodyWarper.res"
	-@erase "$(INTDIR)\BodyWarperDoc.obj"
	-@erase "$(INTDIR)\BodyWarperView.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\FloatMatrix.obj"
	-@erase "$(INTDIR)\InsufficientLandmarksDlg.obj"
	-@erase "$(INTDIR)\LandmarkMapping.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PointMesh.obj"
	-@erase "$(INTDIR)\PointSet.obj"
	-@erase "$(INTDIR)\QuadricSurf.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\BodyWarper.exe"
	-@erase "$(OUTDIR)\BodyWarper.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /w /W0 /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /Gs8000 /c
CPP_PROJ=/nologo /MD /w /W0 /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/BodyWarper.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Gs8000 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x809 /fo"$(INTDIR)/BodyWarper.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/BodyWarper.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/BodyWarper.pdb" /machine:I386 /out:"$(OUTDIR)/BodyWarper.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BicubicSurf.obj" \
	"$(INTDIR)\biquadsurf.obj" \
	"$(INTDIR)\BodyWarper.obj" \
	"$(INTDIR)\BodyWarper.res" \
	"$(INTDIR)\BodyWarperDoc.obj" \
	"$(INTDIR)\BodyWarperView.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\FloatMatrix.obj" \
	"$(INTDIR)\InsufficientLandmarksDlg.obj" \
	"$(INTDIR)\LandmarkMapping.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PointMesh.obj" \
	"$(INTDIR)\PointSet.obj" \
	"$(INTDIR)\QuadricSurf.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\BodyWarper.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "BodyWarper - Win32 Debug"

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

ALL : "$(OUTDIR)\BodyWarper.exe"

CLEAN : 
	-@erase "$(INTDIR)\BicubicSurf.obj"
	-@erase "$(INTDIR)\biquadsurf.obj"
	-@erase "$(INTDIR)\BodyWarper.obj"
	-@erase "$(INTDIR)\BodyWarper.pch"
	-@erase "$(INTDIR)\BodyWarper.res"
	-@erase "$(INTDIR)\BodyWarperDoc.obj"
	-@erase "$(INTDIR)\BodyWarperView.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\FloatMatrix.obj"
	-@erase "$(INTDIR)\InsufficientLandmarksDlg.obj"
	-@erase "$(INTDIR)\LandmarkMapping.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PointMesh.obj"
	-@erase "$(INTDIR)\PointSet.obj"
	-@erase "$(INTDIR)\QuadricSurf.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\BodyWarper.exe"
	-@erase "$(OUTDIR)\BodyWarper.ilk"
	-@erase "$(OUTDIR)\BodyWarper.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /Gs8000 /c
CPP_PROJ=/nologo /MDd /w /W0 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/BodyWarper.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /Gs8000 /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x809 /fo"$(INTDIR)/BodyWarper.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/BodyWarper.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/BodyWarper.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/BodyWarper.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BicubicSurf.obj" \
	"$(INTDIR)\biquadsurf.obj" \
	"$(INTDIR)\BodyWarper.obj" \
	"$(INTDIR)\BodyWarper.res" \
	"$(INTDIR)\BodyWarperDoc.obj" \
	"$(INTDIR)\BodyWarperView.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\FloatMatrix.obj" \
	"$(INTDIR)\InsufficientLandmarksDlg.obj" \
	"$(INTDIR)\LandmarkMapping.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PointMesh.obj" \
	"$(INTDIR)\PointSet.obj" \
	"$(INTDIR)\QuadricSurf.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\BodyWarper.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "BodyWarper - Win32 Release"
# Name "BodyWarper - Win32 Debug"

!IF  "$(CFG)" == "BodyWarper - Win32 Release"

!ELSEIF  "$(CFG)" == "BodyWarper - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "BodyWarper - Win32 Release"

!ELSEIF  "$(CFG)" == "BodyWarper - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\BodyWarper.cpp
DEP_CPP_BODYW=\
	"..\bldefs.h"\
	".\BodyWarper.h"\
	".\BodyWarperDoc.h"\
	".\BodyWarperView.h"\
	".\ChildFrm.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\inttypes.h"\
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
	{$(INCLUDE)}"\Inventor\nodes\SoCoordinate3.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNonIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormalBinding.h"\
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
	{$(INCLUDE)}"\Ivf\IvfMainfrm.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfExaminerViewer.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfRenderArea.h"\
	{$(INCLUDE)}"\Ivf\Viewers\IvfStdViewer.h"\
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\BodyWarper.obj" : $(SOURCE) $(DEP_CPP_BODYW) "$(INTDIR)"\
 "$(INTDIR)\BodyWarper.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "BodyWarper - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /w /W0 /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/BodyWarper.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Gs8000 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\BodyWarper.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "BodyWarper - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /w /W0 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/BodyWarper.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /Gs8000 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\BodyWarper.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	"..\bldefs.h"\
	".\BodyWarper.h"\
	".\BodyWarperView.h"\
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
 "$(INTDIR)\BodyWarper.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	"..\bldefs.h"\
	".\BodyWarper.h"\
	".\ChildFrm.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\BodyWarper.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\BodyWarperDoc.cpp
DEP_CPP_BODYWA=\
	"..\bldefs.h"\
	".\BodyWarper.h"\
	".\BodyWarperDoc.h"\
	".\BodyWarperView.h"\
	".\InsufficientLandmarksDlg.h"\
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
	

"$(INTDIR)\BodyWarperDoc.obj" : $(SOURCE) $(DEP_CPP_BODYWA) "$(INTDIR)"\
 "$(INTDIR)\BodyWarper.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\BodyWarperView.cpp

!IF  "$(CFG)" == "BodyWarper - Win32 Release"

DEP_CPP_BODYWAR=\
	"..\bldefs.h"\
	".\BodyWarper.h"\
	".\BodyWarperDoc.h"\
	".\BodyWarperView.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\inttypes.h"\
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
	{$(INCLUDE)}"\Inventor\nodes\SoCoordinate3.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNonIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormalBinding.h"\
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
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\BodyWarperView.obj" : $(SOURCE) $(DEP_CPP_BODYWAR) "$(INTDIR)"\
 "$(INTDIR)\BodyWarper.pch"


!ELSEIF  "$(CFG)" == "BodyWarper - Win32 Debug"

DEP_CPP_BODYWAR=\
	"..\bldefs.h"\
	".\BodyWarper.h"\
	".\BodyWarperDoc.h"\
	".\BodyWarperView.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\_undefs.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\inttypes.h"\
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
	{$(INCLUDE)}"\Inventor\nodes\SoCoordinate3.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoDrawStyle.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoGroup.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterial.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoMaterialBinding.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNode.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNonIndexedShape.h"\
	{$(INCLUDE)}"\Inventor\nodes\SoNormalBinding.h"\
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
	{$(INCLUDE)}"\SoAddPrefix.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\BodyWarperView.obj" : $(SOURCE) $(DEP_CPP_BODYWAR) "$(INTDIR)"\
 "$(INTDIR)\BodyWarper.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\BodyWarper.rc
DEP_RSC_BODYWARP=\
	".\res\BodyWarper.ico"\
	".\res\BodyWarper.rc2"\
	".\res\BodyWarperDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\BodyWarper.res" : $(SOURCE) $(DEP_RSC_BODYWARP) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\InsufficientLandmarksDlg.cpp
DEP_CPP_INSUF=\
	"..\bldefs.h"\
	".\BodyWarper.h"\
	".\InsufficientLandmarksDlg.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Inventor\lock\demoUnlock.h"\
	{$(INCLUDE)}"\Inventor\lock\SoLockMgr.h"\
	{$(INCLUDE)}"\Ivf\IvfApp.h"\
	{$(INCLUDE)}"\Ivf\IvfEnterScope.h"\
	{$(INCLUDE)}"\Ivf\IvfLeaveScope.h"\
	{$(INCLUDE)}"\SoWinEnterScope.h"\
	

"$(INTDIR)\InsufficientLandmarksDlg.obj" : $(SOURCE) $(DEP_CPP_INSUF)\
 "$(INTDIR)" "$(INTDIR)\BodyWarper.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\PointSet.cpp
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
	

"$(INTDIR)\PointSet.obj" : $(SOURCE) $(DEP_CPP_POINT) "$(INTDIR)"\
 "$(INTDIR)\BodyWarper.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\biquadsurf.cpp
DEP_CPP_BIQUA=\
	{$(INCLUDE)}"\biquadsurf.h"\
	
NODEP_CPP_BIQUA=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\biquadsurf.obj" : $(SOURCE) $(DEP_CPP_BIQUA) "$(INTDIR)"\
 "$(INTDIR)\BodyWarper.pch"
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
 "$(INTDIR)\BodyWarper.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\LandmarkMapping.cpp

!IF  "$(CFG)" == "BodyWarper - Win32 Release"

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
 "$(INTDIR)\BodyWarper.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "BodyWarper - Win32 Debug"

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
 "$(INTDIR)\BodyWarper.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\PointMesh.cpp

!IF  "$(CFG)" == "BodyWarper - Win32 Release"

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
 "$(INTDIR)\BodyWarper.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "BodyWarper - Win32 Debug"

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
 "$(INTDIR)\BodyWarper.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

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
 "$(INTDIR)\BodyWarper.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\Documents\Code\QuadricSurf.cpp
DEP_CPP_QUADR=\
	{$(INCLUDE)}"\QuadricSurf.h"\
	
NODEP_CPP_QUADR=\
	"..\..\..\Code\stdafx.h"\
	

"$(INTDIR)\QuadricSurf.obj" : $(SOURCE) $(DEP_CPP_QUADR) "$(INTDIR)"\
 "$(INTDIR)\BodyWarper.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
