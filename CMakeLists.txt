cmake_minimum_required(VERSION 3.10)

project(qsim)

set(CMAKE_C_STANDARD 11)

# Add the executable
add_executable(qsim
    test/main.c
    lib/qsim.c
)

# Add the include directory to the include path
target_include_directories(qsim PUBLIC include)

# Link the math library
target_link_libraries(qsim m)