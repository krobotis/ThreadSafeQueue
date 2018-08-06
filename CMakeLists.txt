cmake_minimum_required (VERSION 3.2)
project (ThreadSafeQueue)

FILE(GLOB MY_HEADERS "include/*.h")

add_library(ThreadSafeQueue INTERFACE)
target_include_directories(ThreadSafeQueue INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
add_executable(ThreadSafeQueueTest src/main.cpp ${MY_HEADERS})
add_test(ThreadSafeQueueTest ThreadSafeQueue)
target_link_libraries(ThreadSafeQueueTest ThreadSafeQueue)