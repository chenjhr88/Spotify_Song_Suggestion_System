# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# cs225_sources at lib/CMakeLists.txt:12 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/final/cs225_final_proj/lib/cs225/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/final/cs225_final_proj/lib/cs225/HSLAPixel.cpp"
  "/workspaces/cs225/final/cs225_final_proj/lib/cs225/PNG.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/final/cs225_final_proj/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/final/cs225_final_proj/lib/lodepng/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/final/cs225_final_proj/lib/lodepng/lodepng.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/final/cs225_final_proj/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/final/cs225_final_proj/lib/lodepng/*.h")
set(OLD_GLOB
  "/workspaces/cs225/final/cs225_final_proj/lib/lodepng/lodepng.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/final/cs225_final_proj/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/final/cs225_final_proj/src/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/final/cs225_final_proj/src/adjacencylist.cpp"
  "/workspaces/cs225/final/cs225_final_proj/src/code.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/final/cs225_final_proj/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:131 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/final/cs225_final_proj/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/final/cs225_final_proj/tests/tests.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/final/cs225_final_proj/build/CMakeFiles/cmake.verify_globs")
endif()
