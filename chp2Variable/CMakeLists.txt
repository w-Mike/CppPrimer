STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )
set(TARGET ${CURRENT_FOLDER})
include_directories(./include)

aux_source_directory(. SRC_LIST)
add_executable(${TARGET} ${SRC_LIST})

