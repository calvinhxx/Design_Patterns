cmake_minimum_required(VERSION 3.5)

# set the project name
project(Design_Patterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.6)

# set app name
set(NAME App)

# set output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/release)

# add source_files macro function
macro(source_group_by_dir source_files)
        set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR}/)
        foreach(sgbd_file ${${source_files}})
                string(REGEX REPLACE ${sgbd_cur_dir} "" sgbd_fpath ${sgbd_file})
                string(REGEX REPLACE "[^/\\\\]+$" "" sgbd_group_name ${sgbd_fpath})
                if(sgbd_group_name)
                        string(REPLACE "/"   "\\\\"  sgbd_group_name_normal ${sgbd_group_name})
#                        message(STATUS ${sgbd_group_name_normal})
                        source_group(${sgbd_group_name_normal} FILES ${sgbd_file})
                endif(sgbd_group_name)
        endforeach(sgbd_file)
endmacro(source_group_by_dir)

# find files recurse
file(GLOB_RECURSE All_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
source_group_by_dir(All_SOURCES)
foreach(v ${All_SOURCES})
    message(${v})
endforeach()

# create the executable
add_executable(${NAME} ${All_SOURCES} )


