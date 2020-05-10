##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Crossword
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/jaege/OneDrive/Documents/GitHub/Crossword
ProjectPath            :=C:/Users/jaege/OneDrive/Documents/GitHub/Crossword/Crossword
IntermediateDirectory  :=../build-$(ConfigurationName)/Crossword
OutDir                 :=../build-$(ConfigurationName)/Crossword
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jaege
Date                   :=29/04/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/msys64/mingw64/bin/ar.exe rcu
CXX      := C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Crossword/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Crossword/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Crossword" mkdir "..\build-$(ConfigurationName)\Crossword"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Crossword" mkdir "..\build-$(ConfigurationName)\Crossword"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Crossword/.d:
	@if not exist "..\build-$(ConfigurationName)\Crossword" mkdir "..\build-$(ConfigurationName)\Crossword"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Crossword/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/Crossword/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/jaege/OneDrive/Documents/GitHub/Crossword/Crossword/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Crossword/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Crossword/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Crossword/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/Crossword/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Crossword/main.c$(PreprocessSuffix) main.c


-include ../build-$(ConfigurationName)/Crossword//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


