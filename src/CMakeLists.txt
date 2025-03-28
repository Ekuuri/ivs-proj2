set(SOURCES
    calc.cpp
    mathlib-code.cpp
    profiling.cpp
)

set(HEADERS
    calc-ui.h
    mathlib-code.h
)

add_executable(epicCalculator ${SOURCES} ${HEADERS})

# Link Qt
target_link_libraries(epicCalculator Qt5::Core Qt5::Gui Qt5::Widgets)