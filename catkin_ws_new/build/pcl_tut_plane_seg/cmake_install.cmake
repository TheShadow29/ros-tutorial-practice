# Install script for directory: /home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/src/pcl_tut_plane_seg

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/build/pcl_tut_plane_seg/catkin_generated/installspace/pcl_tut_plane_seg.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl_tut_plane_seg/cmake" TYPE FILE FILES
    "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/build/pcl_tut_plane_seg/catkin_generated/installspace/pcl_tut_plane_segConfig.cmake"
    "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/build/pcl_tut_plane_seg/catkin_generated/installspace/pcl_tut_plane_segConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl_tut_plane_seg" TYPE FILE FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/src/pcl_tut_plane_seg/package.xml")
endif()

