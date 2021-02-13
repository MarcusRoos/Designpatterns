# Add source directory
aux_source_directory(src/ SOURCES)
aux_source_directory(../_CodeBase/Hanoi/src SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_5 ${SOURCES} include/Command.h src/Replay.cpp include/Replay.h src/MoveCommand.cpp include/MoveCommand.h src/ResetCommand.cpp include/ResetCommand.h src/ShowCommand.cpp include/ShowCommand.h src/CommandManager.cpp include/CommandManager.h src/Management.cpp src/Management.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_5 PRIVATE include/ ../_CodeBase/Hanoi/include/ ../_CodeBase/_libs/)