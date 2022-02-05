cmake_minimum_required(VERSION 3.21)
project(hangeul-id VERSION 0.1.1 DESCRIPTION "Unique id using hangeul" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)
file(GLOB_RECURSE HEADER_FILES "src/*.h")
file(GLOB_RECURSE CODE_FILES "src/*.cpp")

find_package(Boost REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_library(HANGEUL_ID_LIB_PATH libhangeul-id.a)
find_path(HANGEUL_ID_INCLUDE_DIR NAMES hangeul_id/HangeulId.h)
add_executable(hangeul-id-cli ${HEADER_FILES} ${CODE_FILES})

target_include_directories(hangeul-id-cli PRIVATE ${HANGEUL_ID_INCLUDE_DIR})
target_link_libraries(hangeul-id-cli PRIVATE Catch2::Catch2)
target_link_libraries(hangeul-id-cli PRIVATE CLI11::CLI11)
target_link_libraries(hangeul-id-cli PRIVATE Boost::boost)
target_link_libraries(hangeul-id-cli PRIVATE ${HANGEUL_ID_LIB_PATH})

install(TARGETS hangeul-id-cli RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)