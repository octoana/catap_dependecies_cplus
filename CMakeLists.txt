cmake_minimum_required(VERSION 3.15)
project(cpp-sfml-sqlite-test)

set(CMAKE_CXX_STANDARD 17)

# Enable vcpkg integration
if(DEFINED ENV{VCPKG_ROOT} AND EXISTS "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)
find_package(SQLite3 3.50.3 REQUIRED)

add_executable(cpp-sfml-sqlite-test main.cpp)
target_link_libraries(cpp-sfml-sqlite-test PRIVATE SFML::Graphics SFML::Window SFML::System SQLite::SQLite3)
