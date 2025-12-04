# Install script for directory: C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/XO/cmake_install.cmake")
  include("C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/Numerical9/cmake_install.cmake")
  include("C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/Misere/cmake_install.cmake")
  include("C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/XO4x4/cmake_install.cmake")
  include("C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/Obstacles/cmake_install.cmake")
  include("C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/FiveByFive/cmake_install.cmake")
  include("C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/Infinity/cmake_install.cmake")
  include("C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/SUS/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Yasmine/CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
