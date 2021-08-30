##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CCubeRubikSolver
ConfigurationName      :=Debug
WorkspacePath          :=/home/papa/CodeLiteWls
ProjectPath            :=/home/papa/CodeLiteWls/CCubeRubikSolver
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Papa
Date                   :=29/08/21
CodeLitePath           :=/home/papa/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="CCubeRubikSolver.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/pcube.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/piece.c$(ObjectSuffix) $(IntermediateDirectory)/colors.c$(ObjectSuffix) $(IntermediateDirectory)/base.c$(ObjectSuffix) $(IntermediateDirectory)/cube.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/pcube.c$(ObjectSuffix): pcube.c $(IntermediateDirectory)/pcube.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/pcube.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pcube.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pcube.c$(DependSuffix): pcube.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pcube.c$(ObjectSuffix) -MF$(IntermediateDirectory)/pcube.c$(DependSuffix) -MM pcube.c

$(IntermediateDirectory)/pcube.c$(PreprocessSuffix): pcube.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pcube.c$(PreprocessSuffix) pcube.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/piece.c$(ObjectSuffix): piece.c $(IntermediateDirectory)/piece.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/piece.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/piece.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/piece.c$(DependSuffix): piece.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/piece.c$(ObjectSuffix) -MF$(IntermediateDirectory)/piece.c$(DependSuffix) -MM piece.c

$(IntermediateDirectory)/piece.c$(PreprocessSuffix): piece.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/piece.c$(PreprocessSuffix) piece.c

$(IntermediateDirectory)/colors.c$(ObjectSuffix): colors.c $(IntermediateDirectory)/colors.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/colors.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/colors.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/colors.c$(DependSuffix): colors.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/colors.c$(ObjectSuffix) -MF$(IntermediateDirectory)/colors.c$(DependSuffix) -MM colors.c

$(IntermediateDirectory)/colors.c$(PreprocessSuffix): colors.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/colors.c$(PreprocessSuffix) colors.c

$(IntermediateDirectory)/base.c$(ObjectSuffix): base.c $(IntermediateDirectory)/base.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/base.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/base.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/base.c$(DependSuffix): base.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/base.c$(ObjectSuffix) -MF$(IntermediateDirectory)/base.c$(DependSuffix) -MM base.c

$(IntermediateDirectory)/base.c$(PreprocessSuffix): base.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/base.c$(PreprocessSuffix) base.c

$(IntermediateDirectory)/cube.c$(ObjectSuffix): cube.c $(IntermediateDirectory)/cube.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/cube.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cube.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cube.c$(DependSuffix): cube.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cube.c$(ObjectSuffix) -MF$(IntermediateDirectory)/cube.c$(DependSuffix) -MM cube.c

$(IntermediateDirectory)/cube.c$(PreprocessSuffix): cube.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cube.c$(PreprocessSuffix) cube.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


