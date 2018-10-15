//Project:  CIS023_F2018_HW15 Tom Chaparas
//Module:   CIS023_F2018_HW15 Tom Chaparas.cpp
//Author:   Tom Chaparas
//Date:     October 14,2018
//Purpose:  Practice using recursion to solve a problem.
//          Perform recursion within an object.
//          Use a recursive process to implement a recursive algorithm.

#include "stdafx.h"
#include "CIS023_F2018_HW15 Tom Chaparas.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Fib_1;                                //handle for edit control to get user input 1
HWND hWnd_Fib_2;                                //handle for user input 2
HWND hWnd_Fib_Pos;                              //handle for user input 3
HWND hWnd_Fib_Result;                           //handle for control that displays results
HWND hWnd_B1;                                   //button ontrol


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//Exception classes
class Zero1 {};
class Zero2 {};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CIS023_F2018_HW15TOMCHAPARAS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_F2018_HW15TOMCHAPARAS));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_F2018_HW15TOMCHAPARAS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_F2018_HW15TOMCHAPARAS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 400, 300, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case BN_CLICKED:
            {
                if ((LOWORD(lParam) == (WORD)hWnd_B1))
                {
                    int iInput1 = 0;                            //Fib #1 from user after TCHAR to Int conversion
                    int iInput2 = 0;                            //Fib #2 from user after TCHAR to Int conversion                        
                    int iInput3 = 0;                            //Fib Position from user after TCHAR to Int conversion
                    int iCount = 0;                             //number of positions to move backward
                    
                  
                    TCHAR szInput = '0';                      //TCHAR for user input


                    SendMessage(hWnd_Fib_1,
                        WM_GETTEXT,
                        TCHAR_SIZE,
                        (LPARAM)szInput);
                  
                    /* SendMessage(hWnd_Fib_1,                 //get 1st Fib #
                        WM_GETTEXT,
                        TCHAR_SIZE,
                        (LPARAM)szInput[0]);

                    iInput1 = TCHARtoInt(szInput[0], 10);     //converting TCHARs to int

                    SendMessage(hWnd_Fib_2,                 //get 2nd Fib #
                        WM_GETTEXT,
                        100,
                        (LPARAM)szInput[1]);

                    iInput2 = TCHARtoInt(szInput[1], 10); 

                    SendMessage(hWnd_Fib_Pos,                 //get Fib# position
                        WM_GETTEXT,
                        TCHAR_SIZE,
                        (LPARAM)szInput[2]);

                    iInput3 = TCHARtoInt(szInput[2], 10);
                      
                    iCount = iInput3;
                    //Fibonacci  overloaded constructor
                    FibonacciRecursion Recur1(hWnd_Fib_1, iCount, iInput1, iInput2, iInput3);*/
                   


                }
            }
            break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_CREATE:
    {
        CreateWindow(
            TEXT("STATIC"),
            TEXT("Enter 1st Fibonacci number: "),
            WS_VISIBLE | WS_CHILD,
            20, 20, 300, 30, hWnd, NULL, NULL, NULL);

        hWnd_Fib_1 = CreateWindow(
            TEXT("EDIT"),
            TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER |
            ES_AUTOHSCROLL,
            220, 20, 20, 20, hWnd, NULL, NULL, NULL);

        CreateWindow(
            TEXT("STATIC"),
            TEXT("Enter 2nd Fibonacci number: "),
            WS_VISIBLE | WS_CHILD,
            20, 50, 300, 30, hWnd, NULL, NULL, NULL);

        hWnd_Fib_2 = CreateWindow(
            TEXT("EDIT"),
            TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER |
            ES_AUTOHSCROLL,
            220, 50, 20, 20, hWnd, NULL, NULL, NULL);

        CreateWindow(
            TEXT("STATIC"),
            TEXT("Enter Position of desired Fibonacci number: "),
            WS_VISIBLE | WS_CHILD,
            20, 80, 300, 30, hWnd, NULL, NULL, NULL);

        hWnd_Fib_Pos = CreateWindow(
            TEXT("EDIT"),
            TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER |
            ES_AUTOHSCROLL,
            320, 80, 20, 20, hWnd, NULL, NULL, NULL);

        CreateWindow(
            TEXT("STATIC"),
            TEXT("Fibonacci number at position XX is: "),
            WS_VISIBLE | WS_CHILD,
            20, 110, 300, 30, hWnd, NULL, NULL, NULL);


        hWnd_B1 = CreateWindow(
            TEXT("BUTTON"), TEXT("CALCULATE"),
            WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            120, 175, 100, 30, hWnd, NULL, NULL, NULL);

        

    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
