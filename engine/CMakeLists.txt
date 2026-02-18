add_library(engine STATIC)

target_link_libraries(engine PRIVATE user32 gdi32)

# Collect all cpp source files under src/ and all headers under include/
file(GLOB_RECURSE ENGINE_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE ENGINE_HEADERS
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

# Add sources and expose headers as a FILE_SET so IDEs and install rules
# can group them by folder
target_sources(engine
    PRIVATE
        ${ENGINE_SOURCES}
    PUBLIC
        FILE_SET HEADERS
            BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
            FILES ${ENGINE_HEADERS}
)

target_include_directories(engine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(engine PUBLIC cxx_std_20)

set_target_properties(engine PROPERTIES
    PUBLIC_HEADER "include/engine/Engine.h"
)