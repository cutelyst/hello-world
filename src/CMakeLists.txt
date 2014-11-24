include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Our sources
set(hello_SRCS
    root.cpp
    hello.cpp
)

# Create the application
add_library(hello SHARED ${hello_SRCS})

# Link to Qt modules
qt5_use_modules(hello Core)

# Link to Cutelyst
target_link_libraries(hello
    Cutelyst::cutelyst-qt5 
)

# TODO install to a place where uWSGI Cutelyst plugin searches for
install(TARGETS hello DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
