set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES
    calc.cpp
)

set(HEADERS
    calc.h
    calc-ui.h
    mathlib-code.h
)

add_executable(epicCalculator ${SOURCES} ${HEADERS})

# Link Qt
target_link_libraries(epicCalculator Qt6::Core Qt6::Gui Qt6::Widgets)
