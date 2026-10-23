cmake_minimum_required(VERSION 3.20)

project(NEXUS LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(nexus
    main.c
    src/commands.c
    src/command_handlers.c
)

target_include_directories(nexus PRIVATE include)
