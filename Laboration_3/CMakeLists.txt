# Add source directory
aux_source_directory(src/ SOURCES)
aux_source_directory(../_CodeBase/PowerSource/src SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_3 ${SOURCES} include/Car.h include/SpaceShuttle.h include/Submarine.h include/Vehicle.h src/Car.cpp src/SpaceShuttle.cpp src/Submarine.cpp src/Vehicle.cpp src/Helper.cpp include/Helper.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_3 PRIVATE include/ ../_CodeBase/PowerSource/include/ ../_CodeBase/_libs/)