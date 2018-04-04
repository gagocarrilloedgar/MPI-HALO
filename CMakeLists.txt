
cmake_minimum_required(VERSION 3.0)

project(HALO)
file (GLOB SOURCES "./*.c")
set (CMAKE_C_COMPILER gcc)

find_package(MPI REQUIRED)

add_executable(main ${SOURCES})

target_link_libraries(main
  PRIVATE
  ${MPI_C_LIBRARIES})

target_include_directories(main
  PRIVATE
  ${MPI_C_INCLUDE_PATH}) 

