//Project:  CIS023_F2018_HW15 Tom Chaparas
//Module:   FibonacciRecursion.cpp
//Author:   Tom Chaparas
//Date:     October 14,2018
//Purpose:  Implementation file for FibonacciRecursion.h

#include "stdafx.h"
#include "FibonacciRecursion.h"


FibonacciRecursion::FibonacciRecursion()
{
}


FibonacciRecursion::FibonacciRecursion(HWND hWnd, int iCount, int iFib1, int iFib2, int iFibPos)
{
    //base case.  If final position of Fibonacci number(user selection) is <= 1, function ends
    if (iCount == 1)                   
    { 
        return;
    }   
    else
    {
        //Claculate Fibonacci values based on user input paramenters
        FibonacciRecursion Recur1(hWnd, iCount - 1, iFib1, iFib2, iFibPos);
        FibonacciRecursion Recur2(hWnd, iCount - 1, iFib1, iFib2, iFibPos);

        //Send message to hWnd_Fib_Result with final value
        //WM_SETTEXT(hWnd_Fib_Result, szMessage);

        //recursion fully wound, signal to unwind
        return;
    }



}

FibonacciRecursion::~FibonacciRecursion()
{
}
