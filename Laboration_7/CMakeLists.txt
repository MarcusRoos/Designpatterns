# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_7 ${SOURCES} src/Action.cpp include/Action.h src/Game.cpp include/Game.h src/GameFactory.cpp include/GameFactory.h src/Obstacle.cpp include/Obstacle.h src/Player.cpp include/Player.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_7 PRIVATE include/ ../_CodeBase/_libs/)