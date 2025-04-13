cmake_minimum_required(VERSION 3.30)
project(CENG_218_Document_Indexing)

set(CMAKE_CXX_STANDARD 20)

add_executable(CENG_218_Document_Indexing main.cpp
        IndexNode.cpp
        IndexNode.h
        IndexNodeList.cpp
        IndexNodeList.h
        WordNode.cpp
        WordNode.h
        WordNodeList.cpp
        WordNodeList.h
)
