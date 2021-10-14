project(src)

set(HEADER_FILES

        )

set(SOURCE_FILES
  palindrome.cpp
        palindromes-store/palindromesStore.h palindromes-store/palindromesStoreStub.cpp palindromes-store/palindromesStoreStub.h)

add_executable(src_run main.cpp)
add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})