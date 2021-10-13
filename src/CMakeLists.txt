project(src)

set(HEADER_FILES

        )

set(SOURCE_FILES
  palindrome.cpp
        )

add_executable(src_run main.cpp)
add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})