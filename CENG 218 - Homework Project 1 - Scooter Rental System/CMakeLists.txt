cmake_minimum_required(VERSION 3.30)
project(CENG_218___Homework_Project_1___Scooter_Rental_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(CENG_218___Homework_Project_1___Scooter_Rental_System main.cpp
        Customers.cpp
        Customers.h
        Scooter.cpp
        Scooter.h
        ScooterRentalSystem.cpp
        ScooterRentalSystem.h
        Rental.cpp
        Rental.h)
