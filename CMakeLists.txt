cmake_minimum_required(VERSION 3.19)
cmake_policy(SET CMP0048 NEW)

project(CoolerSockets VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin)

include_directories(
    include/
    lib/CoolSockets/include
)
set(SOURCES
    source/CoolerSockets.cpp
)

add_executable(Server examples/Server.cpp ${SOURCES})
add_executable(Client examples/Client.cpp ${SOURCES})
add_library(${PROJECT_NAME} STATIC ${SOURCES})

if(WIN32)
    target_link_libraries(Server ${PROJECT_SOURCE_DIR}/lib/CoolSockets/lib/CoolSockets.lib wsock32 ws2_32)
    target_link_libraries(Client ${PROJECT_SOURCE_DIR}/lib/CoolSockets/lib/CoolSockets.lib wsock32 ws2_32)
endif()