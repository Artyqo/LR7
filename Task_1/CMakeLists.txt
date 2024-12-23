project(Task_1)

add_executable(Task_1 Task_1.cpp functions_1.cpp)


#[[if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
endif()]]
