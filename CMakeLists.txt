
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
# Update submodules as needed
#set(GIT_EXECUTABLE "git")
#option(GIT_SUBMODULE "Check submodules during build" ON)
#if(GIT_SUBMODULE)
#    message(STATUS "Submodule update")
#    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive gnuplot-iostream WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} RESULT_VARIABLE GIT_SUBMOD_RESULT)
#    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
#        message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
#    endif()
#endif()

#find_package(Boost REQUIRED COMPONENTS iostreams system filesystem)

#include_directories(gnuplot-iostream)
#add_executable(PlotConvergence
#        PlotConvergence.cpp)
#target_compile_features(PlotConvergence PRIVATE cxx_std_17)
#target_link_libraries(PlotConvergence PRIVATE
#        Boost::iostreams
#        Boost::system
#        Boost::filesystem
#)


