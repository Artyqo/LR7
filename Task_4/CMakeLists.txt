project(Task_4)

add_executable(Task_4 Task_4.cpp functions_4.cpp)

#[[
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
endif()]]
