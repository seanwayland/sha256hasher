cmake_minimum_required(VERSION 3.12)
project(sha256 C)

set(CMAKE_C_STANDARD 99)

link_libraries(ssl)
link_libraries(crypto)

add_executable(sha256 main.c)