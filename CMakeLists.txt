cmake_minimum_required(VERSION 3.14)
project(Project_02)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_02 main.h main.cpp state_transitions.cpp tokenizer.cpp DatalogProgram.cpp DatalogProgram.h Rule.cpp Rule.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h)