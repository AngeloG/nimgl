project(nimgl)
cmake_minimum_required(VERSION 2.8)

add_executable(${PROJECT_NAME}
  main.cpp

  StdH.h StdHP.h
  NimGL.cpp NimGL.h NimGL_internal.h
  NContext.cpp NContext.h
  NWindow.cpp NWindow.h
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMakeModules")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${GLEW_INCLUDE_DIRS}
  ${GLM_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
  ${SDL2_LIBRARY}
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
)
