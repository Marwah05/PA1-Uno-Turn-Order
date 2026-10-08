cmake_minimum_required(VERSION 4.3)
project(PA1_Uno_Turn_Order)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA1_Uno_Turn_Order
        main.cpp
        Player.h
        Stack.h
        ArrayList.h
        Data.h
        List.h
        LinkedList.h)
