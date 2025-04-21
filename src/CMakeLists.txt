set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(SOURCES
    calc.cpp
    mathlib-code.cpp
    parser.cpp
)

set(HEADERS
    calc.h
    calc-ui.h
    mathlib-code.h
    parser.h
)

set(UIS
    calc.ui
)

add_executable(epicCalculator 
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

add_executable(mathlibTest
    mathlib-code.cpp
    mathlib-code.h
    mathlib-test.cpp
)

# Link Qt
target_link_libraries(epicCalculator
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

target_link_libraries(mathlibTest
    gtest
    gtest_main
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
