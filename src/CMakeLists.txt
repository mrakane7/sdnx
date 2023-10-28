add_executable (SDNX "sdnx.cpp" "include/window.h" "window.cpp" "include/sdnx.h" "sdnx.rc" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SDNX PROPERTY CXX_STANDARD 20)
endif()