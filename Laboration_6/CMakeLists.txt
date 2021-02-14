# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_6 ${SOURCES} src/ConcreteComponents.cpp include/ConcreteComponents.h src/ConcreteDecorators.cpp include/ConcreteDecorators.h include/MainComponent.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_6 PRIVATE include/ ../_CodeBase/_libs/)