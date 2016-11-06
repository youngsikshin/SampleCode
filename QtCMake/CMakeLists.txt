cmake_minimum_required(VERSION 2.8)

file(GLOB qt_path /opt/Qt*)

if(EXISTS ${qt_path})
  set(CMAKE_PREFIX_PATH ${qt_path}/5.7/gcc_64/lib/cmake)
  message("-- CMAKE_PREFIX_PATH is " ${qt_path}/5.7/gcc_64/lib/cmake)
endif()

project(QtCMake)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Qt{4,5} have been find_package'd() by FindQGLViewer.cmake
FIND_PACKAGE(Qt5 QUIET COMPONENTS Core Xml OpenGL Gui Widgets)
IF(NOT Qt5_FOUND)
	FIND_PACKAGE(Qt4 COMPONENTS QtCore QtXml QtOpenGL QtGui)
	IF(NOT Qt4_FOUND AND NOT Qt5_FOUND)
		MESSAGE("Qt{4,5} not found. Install it and set Qt{4,5}_DIR accordingly")
		IF (WIN32)
			MESSAGE("  In Windows, Qt5_DIR should be something like C:/Qt/5.4/msvc2013_64_opengl/lib/cmake/Qt5")
		ENDIF()
	ENDIF()
ENDIF()

if(Qt4_FOUND)
  include(${QT_USE_FILE})

  QT4_WRAP_UI(UI_HEADERS qtcmakesample.ui)
  QT4_WRAP_CPP(UI_SOURCES qtcmakesample.h)

  include_directories(${QT_INCLUDES})
  set(MY_QT_LIBRARIES ${QT_LIBRARIES})
endif()

if(Qt5_FOUND)
  QT5_WRAP_UI(UI_HEADERS qtcmakesample.ui)
  QT5_WRAP_CPP(UI_SOURCES qtcmakesample.h)

  include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS}
)
  set(MY_QT_LIBRARIES ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES}
)
endif()


#INCLUDE_DIRECTORIES(${QGLVIEWER_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_library(qtcmakesample_library
  qtcmakesample.cpp qtcmakesample.h
  ${UI_HEADERS} ${UI_SOURCES}
)

add_executable(qtcmakesample main.cpp)

target_link_libraries(qtcmakesample_library ${QGLVIEWER_LIBRARY} ${MY_QT_LIBRARIES} ${OPENGL_LIBRARY})
target_link_libraries(qtcmakesample qtcmakesample_library)
