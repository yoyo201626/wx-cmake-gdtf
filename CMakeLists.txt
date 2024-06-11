cmake_minimum_required (VERSION 3.8)

project(myapp)

if (WIN32)
    set(DO_NOT_INCLUDE_MINI_ZIP FALSE)
    set(xmlch-type wchar_t)
    set(BUILD_MVR_XCHANGE_EXAMPLE FALSE)
    set(DONT_USE_XERCES_AS_XMLLIB TRUE)
    set(BUILD_MVR_XCHANGE FALSE)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/libMVRgdtf)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/libMVRgdtf/src/Include)

add_executable(myapp src/main.cpp)

link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/boost)

target_link_libraries(myapp MvrGdtf)

if (WIN32)
    # set_target_properties(myapp PROPERTIES
    #     LINK_FLAGS "/SUBSYSTEM:WINDOWS"
    # )
endif()