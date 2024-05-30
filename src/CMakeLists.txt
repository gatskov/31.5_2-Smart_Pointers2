cmake_minimum_required (VERSION 3.24)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable (SmartPointers2  "main.cpp" "Toy.cpp" "SaredToyRtr.cpp" "checkBolock.cpp" " ${MY_INCLUDE_DIR}/checkblock.h" " ${MY_INCLUDE_DIR}/shared_toy_ptr.h" " ${MY_INCLUDE_DIR}/Toy.h")
target_include_directories(SmartPointers1 PUBLIC ${MY_INCLUDE_DIR})
