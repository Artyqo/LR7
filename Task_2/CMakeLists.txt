project(Task_2)

add_executable(Task_2 Task_2.cpp functions_2.cpp)

#[[
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
endif()]]
