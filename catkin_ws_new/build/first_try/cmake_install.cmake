# Install script for directory: /home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/src/first_try

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/first_try/msg" TYPE FILE FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/src/first_try/msg/Num.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/first_try/srv" TYPE FILE FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/src/first_try/srv/AddTwoInts.srv")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/first_try/cmake" TYPE FILE FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/build/first_try/catkin_generated/installspace/first_try-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/devel/include/first_try")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/devel/share/roseus/ros/first_try")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/devel/share/common-lisp/ros/first_try")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/devel/share/gennodejs/ros/first_try")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/devel/lib/python2.7/dist-packages/first_try")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/devel/lib/python2.7/dist-packages/first_try")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/build/first_try/catkin_generated/installspace/first_try.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/first_try/cmake" TYPE FILE FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/build/first_try/catkin_generated/installspace/first_try-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/first_try/cmake" TYPE FILE FILES
    "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/build/first_try/catkin_generated/installspace/first_tryConfig.cmake"
    "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/build/first_try/catkin_generated/installspace/first_tryConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/first_try" TYPE FILE FILES "/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/src/first_try/package.xml")
endif()

