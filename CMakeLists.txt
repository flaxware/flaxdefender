cmake_minimum_required(VERSION 3.20)
project(flaxdefender VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_library(flaxdefender_core
    src/core/Version.cpp
    src/security/FirewallManager.cpp
    src/security/Scanner.cpp
    src/security/Cleaner.cpp
    src/security/Monitor.cpp
    src/security/Crypto.cpp
    src/security/KeyManager.cpp
)

target_include_directories(flaxdefender_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(flaxdefender_app src/main.cpp)
target_link_libraries(flaxdefender_app PRIVATE flaxdefender_core)

if(BUILD_TESTING)
    add_executable(smoke_test tests/SmokeTest.cpp)
    target_link_libraries(smoke_test PRIVATE flaxdefender_core)
    add_test(NAME smoke_test COMMAND smoke_test)
endif()

install(TARGETS flaxdefender_app flaxdefender_core
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
