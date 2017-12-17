cmake_minimum_required(VERSION 3.9)
project(ballern CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(FLEX REQUIRED)
FLEX_TARGET(ballern_scanner
            tokens.ll ${CMAKE_CURRENT_BINARY_DIR}/tokens.cpp
)

find_package(BISON 3.0.0 REQUIRED)
BISON_TARGET(ballern_parser
             grammar.y ${CMAKE_CURRENT_BINARY_DIR}/grammar.cpp
             COMPILE_FLAGS "-d -ra --warnings=deprecated,other,error=conflicts-sr,error=conflicts-rr"
)

ADD_FLEX_BISON_DEPENDENCY(ballern_scanner ballern_parser)

add_executable(ballern
  ${BISON_ballern_parser_OUTPUTS}
  ${FLEX_ballern_scanner_OUTPUTS}
  Parser.cpp
  ballern.cpp
)

target_include_directories(ballern PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
