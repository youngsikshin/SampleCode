cmake_minimum_required(VERSION 2.8)

file(GLOB qt_path /opt/Qt*)

if(EXISTS ${qt_path})
  set(CMAKE_PREFIX_PATH ${qt_path}/5.6/gcc_64/lib/cmake)
  message("-- CMAKE_PREFIX_PATH is " ${qt_path}/5.6/gcc_64/lib/cmake)
endif()

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(OpenGL)
find_package(Qt5 QUIET COMPONENTS Core Xml OpenGL Gui Widgets)

set (QtHELLOSHADER_CPP window.cpp myglwidget.cpp)
set (QtHELLOSHADER_HEADER window.h myglwidget.h)
set (QtHELLOSHADER_UI  window.ui)
set (QtHELLOSHADER_MAIN main.cpp)

if(Qt5_FOUND)
  QT5_WRAP_UI(UI_HEADERS ${QtHELLOSHADER_UI})
  QT5_WRAP_CPP(UI_SOURCES ${QtHELLOSHADER_HEADER})
  QT5_ADD_RESOURCES(SHADER_RSC_ADDED resources.qrc)

  include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS}
)
  set(QtHELLOSHADER_LIBRARIES ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
)
endif()

add_library(qthelloshader_library 
  ${QtHELLOSHADER_HEADER} ${QtHELLOSHADER_CPP}
  ${UI_HEADERS} ${UI_SOURCES}
)

add_executable(qthelloshader ${QtHELLOSHADER_MAIN}  ${SHADER_RSC_ADDED})

target_link_libraries(qthelloshader_library ${QGLVIEWER_LIBRARY} ${QtHELLOSHADER_LIBRARIES} ${OPENGL_LIBRARY})
target_link_libraries(qthelloshader qthelloshader_library)
