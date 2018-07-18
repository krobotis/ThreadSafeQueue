cmake_minimum_required (VERSION 3.2)
project (ThreadSafeQueue)

message(STATUS "\${CMAKE_SOURCE_DIR} = ${CMAKE_SOURCE_DIR}")
message(STATUS "\${CMAKE_BINARY_DIR} = ${CMAKE_BINARY_DIR}")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

FILE(GLOB MY_HEADERS "include/*.h")

add_library(ThreadSafeQueue INTERFACE)
target_include_directories(ThreadSafeQueue INTERFACE ${PROJECT_SOURCE_DIR}/include)


enable_testing()
add_executable(ThreadSafeQueueTest src/main.cpp ${MY_HEADERS})
add_test(ThreadSafeQueueTest ThreadSafeQueue)
target_link_libraries(ThreadSafeQueueTest ThreadSafeQueue)