configure_file(
    ${CMAKE_SOURCE_DIR}/root_directory.h.in
    ${CMAKE_BINARY_DIR}/root_directory.h
)

include_directories(${CMAKE_BINARY_DIR})
