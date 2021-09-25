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
Date                   :=25/09/21
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
Objects0=$(IntermediateDirectory)/RC_Element.c$(ObjectSuffix) $(IntermediateDirectory)/RC_Face.c$(ObjectSuffix) $(IntermediateDirectory)/RC_Coords.c$(ObjectSuffix) $(IntermediateDirectory)/RubikCube.c$(ObjectSuffix) $(IntermediateDirectory)/RC_Tile.c$(ObjectSuffix) $(IntermediateDirectory)/RC_Cube.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/RC_Element.c$(ObjectSuffix): RC_Element.c $(IntermediateDirectory)/RC_Element.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/RC_Element.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RC_Element.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RC_Element.c$(DependSuffix): RC_Element.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RC_Element.c$(ObjectSuffix) -MF$(IntermediateDirectory)/RC_Element.c$(DependSuffix) -MM RC_Element.c

$(IntermediateDirectory)/RC_Element.c$(PreprocessSuffix): RC_Element.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RC_Element.c$(PreprocessSuffix) RC_Element.c

$(IntermediateDirectory)/RC_Face.c$(ObjectSuffix): RC_Face.c $(IntermediateDirectory)/RC_Face.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/RC_Face.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RC_Face.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RC_Face.c$(DependSuffix): RC_Face.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RC_Face.c$(ObjectSuffix) -MF$(IntermediateDirectory)/RC_Face.c$(DependSuffix) -MM RC_Face.c

$(IntermediateDirectory)/RC_Face.c$(PreprocessSuffix): RC_Face.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RC_Face.c$(PreprocessSuffix) RC_Face.c

$(IntermediateDirectory)/RC_Coords.c$(ObjectSuffix): RC_Coords.c $(IntermediateDirectory)/RC_Coords.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/RC_Coords.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RC_Coords.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RC_Coords.c$(DependSuffix): RC_Coords.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RC_Coords.c$(ObjectSuffix) -MF$(IntermediateDirectory)/RC_Coords.c$(DependSuffix) -MM RC_Coords.c

$(IntermediateDirectory)/RC_Coords.c$(PreprocessSuffix): RC_Coords.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RC_Coords.c$(PreprocessSuffix) RC_Coords.c

$(IntermediateDirectory)/RubikCube.c$(ObjectSuffix): RubikCube.c $(IntermediateDirectory)/RubikCube.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/RubikCube.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RubikCube.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RubikCube.c$(DependSuffix): RubikCube.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RubikCube.c$(ObjectSuffix) -MF$(IntermediateDirectory)/RubikCube.c$(DependSuffix) -MM RubikCube.c

$(IntermediateDirectory)/RubikCube.c$(PreprocessSuffix): RubikCube.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RubikCube.c$(PreprocessSuffix) RubikCube.c

$(IntermediateDirectory)/RC_Tile.c$(ObjectSuffix): RC_Tile.c $(IntermediateDirectory)/RC_Tile.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/RC_Tile.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RC_Tile.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RC_Tile.c$(DependSuffix): RC_Tile.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RC_Tile.c$(ObjectSuffix) -MF$(IntermediateDirectory)/RC_Tile.c$(DependSuffix) -MM RC_Tile.c

$(IntermediateDirectory)/RC_Tile.c$(PreprocessSuffix): RC_Tile.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RC_Tile.c$(PreprocessSuffix) RC_Tile.c

$(IntermediateDirectory)/RC_Cube.c$(ObjectSuffix): RC_Cube.c $(IntermediateDirectory)/RC_Cube.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/RC_Cube.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RC_Cube.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RC_Cube.c$(DependSuffix): RC_Cube.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RC_Cube.c$(ObjectSuffix) -MF$(IntermediateDirectory)/RC_Cube.c$(DependSuffix) -MM RC_Cube.c

$(IntermediateDirectory)/RC_Cube.c$(PreprocessSuffix): RC_Cube.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RC_Cube.c$(PreprocessSuffix) RC_Cube.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/papa/CodeLiteWls/CCubeRubikSolver/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


