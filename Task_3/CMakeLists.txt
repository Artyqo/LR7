project(Task_3)

add_executable(Task_3 Task_3.cpp functions_3.cpp)

#[[
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
endif()]]
