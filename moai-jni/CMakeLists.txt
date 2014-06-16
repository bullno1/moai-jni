cmake_minimum_required ( VERSION 2.8.5 )
project(moai-jni)

if(BUILD_ANDROID)
	add_definitions(-DBUILD_ANDROID)
endif()

add_library(moai-jni STATIC
    host.cpp
    luajava.c
)
target_include_directories(moai-jni PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../)
target_link_libraries(moai-jni moai-core moai-util moai-sim zlcore)
