cmake_minimum_required(VERSION 3.5)
project(GeneratedFromCodeGenerator)


set(CMAKE_CXX_STANDARD 20)

# Source files
set(SOURCES
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
        CSVReaderPolynome.cpp
        PlotConvergence.cpp
)

# Submodule update
set(GIT_EXECUTABLE "git")
option(GIT_SUBMODULE "Check submodules during build" ON)
if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive gnuplot-iostream WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    endif()
endif()

# Find Boost
find_package(Boost REQUIRED COMPONENTS
        iostreams system filesystem
)

# Include directories
include_directories(eigen-master)
include_directories(gnuplot-iostream)

# Executable for main
add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE
        Boost::iostreams
        Boost::system
        Boost::filesystem
)

# Executable for test
set(SOURCES_TEST
        result_method.cc
        function.cc
        polynomial_1_to_n.cc
        m_to_n.cc
        find_root.cc
        fixed_point.cc
        newton.cc
        classic_chord.cc
        bissection.cc
        test.cpp
)
add_executable(test ${SOURCES_TEST})
add_subdirectory(googletest)
target_link_libraries(test PRIVATE
        Boost::iostreams
        Boost::system
        Boost::filesystem
        gtest_main
        gtest
        pthread
)

set(DOXYGEN_EXECUTABLE doxygen)
set(DOXYFILE Doxyfile)
add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/${DOXYFILE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
