//Project:  CIS023_F2018_HW15 Tom Chaparas
//Module:   FibonacciRecursion.h
//Author:   Tom Chaparas
//Date:     October 14,2018
//Purpose:  Header file for FibonacciRecursion.cpp
//          Solves for number in Fibonacci sequnce based in user input

#pragma once
class FibonacciRecursion
{
public:
    FibonacciRecursion();                //default constructor

    FibonacciRecursion(                 //overloaded constructor for recursion
        HWND,                           //handle to window
        int,                            //counter
        int,                            //Fib # 1
        int,                            //Fib # 2
        int);                           //position of Fib # 3

    ~FibonacciRecursion();              //destructor

private:
    TCHAR szMessage[TCHAR_SIZE];
};

