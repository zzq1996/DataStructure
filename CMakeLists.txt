cmake_minimum_required(VERSION 3.15)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp chapter2-List/SeqList.h chapter2-List/SinList.h chapter2-List/CircList.h chapter3-StackQueue/SeqStatck.h chapter5-Tree/BInaryTree.h chapter3-StackQueue/LinkedStack.h chapter3-StackQueue/SeqQueue.h chapter3-StackQueue/SeqQueue.cpp chapter2-List/CircList.cpp chapter2-List/SeqList.cpp chapter2-List/SinList.cpp chapter3-StackQueue/LinkedStack.cpp chapter3-StackQueue/SeqStack.cpp chapter7-Sort/Sort.h chapter7-Sort/Sort.cpp chapter8-Search/Search.h chapter8-Search/Search.cpp chapter5-Tree/ThreadTree.h)