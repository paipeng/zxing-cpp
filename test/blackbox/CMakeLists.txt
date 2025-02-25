cmake_minimum_required(VERSION 3.14)

if (BUILD_SYSTEM_DEPS STREQUAL "AUTO")
    find_package (fmt)
elseif (BUILD_SYSTEM_DEPS STREQUAL "ALWAYS")
    find_package (fmt REQUIRED)
endif()

if (NOT fmt_FOUND)
    include(FetchContent)
    FetchContent_Declare (fmtlib
            GIT_REPOSITORY https://github.com/fmtlib/fmt.git
            GIT_TAG 8.0.1)
    FetchContent_MakeAvailable (fmtlib) # Adds fmt::fmt
endif()

if (BUILD_READERS)
    add_executable (ReaderTest
        TestReaderMain.cpp
        ImageLoader.h
        ImageLoader.cpp
        BlackboxTestRunner.h
        BlackboxTestRunner.cpp
        ZXFilesystem.h
    )

    target_link_libraries(ReaderTest
        ZXing::ZXing fmt::fmt stb::stb
        $<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_LESS:$<CXX_COMPILER_VERSION>,9.0>>:stdc++fs>
    )

if (MSVC)
    target_compile_options(ReaderTest PRIVATE
        -D_CRT_SECURE_NO_WARNINGS
    )
endif()

    add_test(NAME ReaderTest COMMAND ReaderTest ${CMAKE_CURRENT_SOURCE_DIR}/../samples)
endif()

if (BUILD_WRITERS)
    add_executable (WriterTest TestWriterMain.cpp)

    target_link_libraries (WriterTest ZXing::ZXing stb::stb)

    add_test(NAME WriterTest COMMAND WriterTest)
endif()
