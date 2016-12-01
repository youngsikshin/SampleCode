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

set (QtGL_CPP window.cpp myglwidget.cpp)
set (QtGL_HEADER window.h myglwidget.h)
set (QtGL_UI  window.ui)
set (QtGL_MAIN main.cpp)

if(Qt5_FOUND)
  QT5_WRAP_UI(UI_HEADERS ${QtGL_UI})
  QT5_WRAP_CPP(UI_SOURCES ${QtGL_HEADER})
  #QT5_ADD_RESOURCES(SHADER_RSC_ADDED resources.qrc)

  include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS}
)
  set(QtGL_LIBRARIES ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
)
endif()

#libhandler_opengl ()

add_library(qtglbegginer_library 
  ${QtGL_HEADER} ${QtGL_CPP}
  ${UI_HEADERS} ${UI_SOURCES}
)

add_executable(qtglbegginer ${QtGL_MAIN})

target_link_libraries(qtglbegginer_library ${QGLVIEWER_LIBRARY} ${QtGL_LIBRARIES} ${OPENGL_LIBRARY})
target_link_libraries(qtglbegginer qtglbegginer_library)
