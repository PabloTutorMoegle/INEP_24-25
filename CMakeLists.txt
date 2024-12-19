cmake_minimum_required(VERSION 3.10)
project(ProjecteEsin)

# Definir variables
set(BLOBS "${CMAKE_SOURCE_DIR}/external_blobs")
set(SRC "${CMAKE_SOURCE_DIR}/src")

# Utilitzar tots els fitxers per crear l'executable
file(
    GLOB_RECURSE SOURCES 
    "${SRC}/*.cpp" 
    "${SRC}/*.hpp"
    "${BLOBS}/src/*.cpp"
)
add_executable(projecte_inep ${SOURCES})

#include_directories("${BLOBS}/include/jdbc")
#include_directories("${BLOBS}/include/mysql")
#include_directories("${BLOBS}/include/mysqlx")
#link_directories("${BLOBS}/private")
#link_directories("${BLOBS}")

target_link_libraries(projecte_inep PRIVATE -lmysqlcppconn)
