# Add source directory
aux_source_directory(src/ SOURCES)
aux_source_directory(../_CodeBase/Hanoi/src SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_5 ${SOURCES} include/Command.h src/HanoiEngine.cpp include/HanoiEngine.h src/HanoiEngine.cpp)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_5 PRIVATE include/ ../_CodeBase/Hanoi/include/ ../_CodeBase/_libs/)