set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(SOURCES
    calc.cpp
)

set(HEADERS
    calc.h
    calc-ui.h
    mathlib-code.h
)

set(UIS
    calc.ui
)

add_executable(epicCalculator ${SOURCES} ${HEADERS} ${UIS})

# Link Qt
target_link_libraries(epicCalculator Qt6::Core Qt6::Gui Qt6::Widgets)
