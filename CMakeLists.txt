
cmake_minimum_required (VERSION 2.6)
project (GeneratedFromCodeGenerator)
include_directories(eigen-master)
add_executable(main
main.cc
result_method.cc
function.cc
polynomial_1_to_n.cc
m_to_n.cc
find_root.cc
fixed_point.cc
newton.cc
classic_chord.cc
bissection.cc
PlotConvergence.cpp
)

#project(PCSC)
#set(GNUPLOT_DIR ${CMAKE_SOURCE_DIR}/gnuplot-iostream)
#include_directories(${GNUPLOT_DIR})
#add_executable(PlotConvergence
#        PlotConvergence.cpp)
#target_link_libraries(PlotConvergence gnuplot-iostream)
