# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_2 ${SOURCES} src/BakingRecepyManager.cpp include/BakingRecepyManager.h include/Ingredient.hpp include/Bakery.h include/NoBakingException.h include/BakingRecepy.h include/Recipes.h src/BakingRecepy.cpp src/Bakery.cpp src/Management.cpp include/Management.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_2 PRIVATE include/ ../_CodeBase/Bakery/ ../_CodeBase/_libs/)