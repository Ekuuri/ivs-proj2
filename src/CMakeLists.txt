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
    mathlib-code.h
    parser.h
)

set(UIS
    calc.ui
)

set(QTlib
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

qt6_wrap_ui(UI_HEADERS ${UIS})

add_executable(epicCalculator 
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
)

add_executable(mathlibTest
    mathlib-code.cpp
    mathlib-code.h
    mathlib-test.cpp
    parser.cpp
    parser.h
    parser-test.cpp
)

add_executable(stddev
    profiling.cpp
    mathlib-code.h
    mathlib-code.cpp
)

# Link Qt
target_link_libraries(epicCalculator
    ${QTlib}
)

target_link_libraries(mathlibTest
    gtest
    gtest_main
    ${QTlib}
)
