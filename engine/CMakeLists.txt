add_library(engine STATIC)

target_sources(engine
    PRIVATE
        src/core/Application.cpp
    PUBLIC
        FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include FILES include/engine/Engine.h
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