cmake_minimum_required(VERSION 3.22)
project(adpcm VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

include_directories(./lib)

file(GLOB TARGET_SRC "./src/*.cpp" )


add_executable(
    main ${TARGET_SRC}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)