cmake_minimum_required(VERSION 3.12)
project(CDSExamples C)

set(CMAKE_C_STANDARD 11)

add_executable(CDSExamples main.c "01 introduction/Scanf.h" "supplementaryExample/01 va_start_example.c" "02_01 SequenceList/SequenceList.c" "02_01 SequenceList/SequenceList.h" "02_01 SequenceList/SequenceList-main.c" "supplementaryExample/02 malloc_demo.c" "02_02 Union/Union.h" "02_02 Union/Union.c" "02_02 Union/Union-main.c")