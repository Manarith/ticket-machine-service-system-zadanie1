cmake_minimum_required(VERSION 3.16)
project(TicketSystem)

set(CMAKE_CXX_STANDARD 20)

add_library(core
    src/server/TicketService.cpp
    src/server/CashRegister.cpp
    src/server/SessionManager.cpp
    src/server/ChangeCalculator.cpp
    src/server/Server.cpp
)

target_include_directories(core PUBLIC include)

add_executable(client src/client/Client.cpp)
target_link_libraries(client core)

enable_testing()

find_package(GTest REQUIRED)

add_executable(tests
    tests/tests.cpp
)

target_link_libraries(tests
    GTest::gtest_main
    core
)

include(GoogleTest)
gtest_discover_tests(tests)