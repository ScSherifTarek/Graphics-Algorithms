#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <math.h>

#define PI 3.14159265359

/* Declare My Procedures */
void lineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);
void lineMidPoint(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

int max(int a, int b)
{
    return (a>b)? a: b;
}

int roundUp(float x)
{
    return (int) x+0.5;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(int &a1, int &b1, int &a2, int &b2)
{
    swap(a1,b1);
    swap(a2,b2);
}

void lineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color)
{
    int dx = x2 - x1,
        dy = y2 - y1,
        numOfPoints = max(abs(dx),abs(dy))+1;

    if(abs(dx)>abs(dy))
    {
        if(x1>x2)
        {
            swap(x1,x2,y1,y2);
        }
        float   m = (float)dy/dx,
            x = x1,
            y = y1;
        while(numOfPoints--)
        {
            SetPixel(hdc,x,roundUp(y),color);
            x++;
            y+=m;
        }
    }
    else
    {
        if(y1>y2)
        {
            swap(x1,x2,y1,y2);
        }
        float   m = (float) dx/dy,
            x = x1,
            y = y1;
        while(numOfPoints--)
        {
            SetPixel(hdc,roundUp(x),y,color);
            x+=m;
            y++;
        }
    }
}

void lineMidPoint(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color)
{


    float m = (float) (y2-y1)/(x2-x1);

    int

        d4,



        chNeg3,
        chNeg4;



    if(m<1 && m >=0)
    {


        std::cout<<x1<<" "<<y1<<std::endl;
        std::cout<<x2<<" "<<y2<<std::endl;
        std::cout<<std::endl;

        if(x1>x2)
            swap(x1,x2,y1,y2);

        int dx = x2 - x1,
            dy = y2 - y1;
        std::cout<<x1<<" "<<y1<<std::endl;
        std::cout<<x2<<" "<<y2<<std::endl;
        std::cout<<std::endl;

        int x = x1,
            y = y1;

        int d1 = dx - 2 * dy,
            chPos1 = dx - dy,
            chPos2 = -dy;
        std::cout<<x<<" "<<x2<<std::endl;

        while(x <= x2)
        {
            SetPixel(hdc,x,y,color);
            if(d1<0)
            {
                y++;
                x++;
                d1 += chPos1;
            }
            else
            {
                x++;
                d1 += chPos2;
            }
        }
    }
    else if(m >=1)
    {
        if(x1>x2)
            swap(x1,x2,y1,y2);

        int dx = x2 - x1,
            dy = y2 - y1;

        int x = x1,
            y = y1;

        int d2 = dx - 0.5 * dy,
            chPos3 = dx,
            chPos4 = dx - dy;

        while(y <= y2)
        {
            SetPixel(hdc,x,y,color);
            if(d2<0)
            {
                y++;
                d2 += chPos3;
            }
            else
            {
                y++;
                x++;
                d2 += chPos4;
            }
        }
    }
    else if(m < 0 && abs(y2-y1) > abs(x2-x1))
    {

        if(y1<y2)
            swap(x1,x2,y1,y2);

        int dx = x2 - x1,
            dy = y2 - y1;
        int x = x1,
            y = y1;


        int d3 = - 2 * dx - dy,
            chNeg1 = - dx - dy,
            chNeg2 = - dx;

        while(y >= y2)
        {
            SetPixel(hdc,x,y,color);
            if(d3<0)
            {
                y--;
                x++;
                d3 += chNeg1;
            }
            else
            {
                y--;
                d3 += chNeg2;
            }
        }
    }
    else if(m < 0 && abs(y2-y1) < abs(x2-x1))
    {

        if(x1>x2)
            swap(x1,x2,y1,y2);

        int dx = x2 - x1,
            dy = y2 - y1;

        int x = x1,
            y = y1;


        int d4 = - 0.5 * dx - dy,
            chNeg3 = - dy,
            chNeg4 = - dx - dy;

        while(x <= x2)
        {
            SetPixel(hdc,x,y,color);
            if(d4<0)
            {
                x++;
                d4 += chNeg3;
            }
            else
            {
                x++;
                y--;
                d4 += chNeg4;
            }
        }
    }
}

void lineParametric(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color)
{
    int x,
        y,
        dx = x2 - x1,
        dy = y2 - y1,
        numOfPoints = max(abs(dx),abs(dy))+1;

    double stepT = 1.0/numOfPoints;
    for(double t=0;t<=1;t+=stepT)
    {
        x = x1 + t * (x2-x1);
        y = y1 + t * (y2-y1);
        SetPixel(hdc,x,y,color);
    }
}


void draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF color)
{
    SetPixel(hdc, xc + x, yc + y, color);
    SetPixel(hdc, xc + x, yc - y, color);
    SetPixel(hdc, xc - x, yc + y, color);
    SetPixel(hdc, xc - x, yc - y, color);
}
/*  This function is called by the Windows function DispatchMessage()  */

void ellipseDirect(HDC hdc, int xc, int yc, int a, int b, COLORREF color)
{
    double x = 0;
    double y = b;
    const double abSquare = a*a*b*b;
    while(x<=a)
    {
        draw4Points(hdc,xc,yc,roundUp(x),roundUp(y),color);
        x += 0.01;
        y = sqrt((abSquare-(b*b*x*x))/(a*a));
    }
}

void ellipseMidPointNotModified(HDC hdc, int xc, int yc, int a, int b, COLORREF color)
{
    int aSquare = a*a,
        bSquare = b*b,
        abSquare = a*a*b*b;

    double d;

    int x = 0,
        y = b;

    while(x<=a)
    {
        draw4Points(hdc,xc,yc,x,y,color);
        d = bSquare * ((x+1) * (x+1)) + aSquare * ((y-0.5) * (y-0.5)) - abSquare;
        if(d<0)
        {
            x++;
        }
        else
        {
            x++;
            y--;
        }
    }
}



void ellipseMidPoint(HDC hdc, int xc, int yc, int a, int b, COLORREF color)
{
    int aSquare = a*a,
        bSquare = b*b,
        abSquare = a*a*b*b,
        constInUnder = 3 * bSquare,
        constInAbove = 10 * aSquare;

    double d,dUnder,dAbove;

    double x = 0,
        y = b;

    while(x<=a && y >= 0)
    {
        d = bSquare * ((x+1) * (x+1)) + aSquare * ((y-0.5) * (y-0.5)) - abSquare;
        dUnder += -x * bSquare + constInUnder;
        if(d<0)
        {
            d += dUnder;
            x+=0.1;
        }
        else
        {
            d += dUnder*4 + 8 * y *  aSquare + constInAbove;
            x+=0.1;
            y--;
        }
        draw4Points(hdc,xc,yc,roundUp(x),roundUp(y),color);
    }
}

#include<cmath>
void ellipsePolar(HDC hdc, int xc, int yc, int a, int b, COLORREF color)
{
    int x,y;
    for(double seta=0;seta<PI/2;seta+=0.001)
    {
        x = roundUp(a * cos(seta));
        y = roundUp(b * sin(seta));
        draw4Points(hdc,xc,yc,x,y,color);
    }
}



LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{


/// line
//    static int x1,y1,x2,y2;

/// ellipse
    static int counter = 3, a, b, xc, yc;

    HDC hdc;
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_LBUTTONDOWN:
            switch(counter)
            {
            case 3:
                xc =LOWORD(lParam);
                yc= HIWORD(lParam);
                break;

            case 2:
                a = abs(xc-LOWORD(lParam));
                break;

            case 1:
                b = abs(yc-HIWORD(lParam));
                hdc = GetDC(hwnd);
                ellipseMidPoint(hdc,xc,yc,a,b,BLACK_BRUSH);
                ReleaseDC(hwnd, hdc);

            default:
                counter=4;
            }
            counter--;
            break;

///Line
//        case WM_LBUTTONDOWN:
//            x1 = LOWORD(lParam);
//            y1 = HIWORD(lParam);
//            break;
//        case WM_LBUTTONUP:
//            x2 =LOWORD(lParam);
//            y2= HIWORD(lParam);
//            hdc = GetDC(hwnd);
//            lineDDA(hdc,x1,y1,x2,y2,BLACK_BRUSH);
//            ReleaseDC(hwnd, hdc);
//            break;

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
//    if(choosed)
//    {
//        int c;
//        std::cin>>c;
//
//        HDC hdc = GetDC(hwnd);
//        switch(c)
//        {
//            case 0:
//                lineDDA(hdc,x1,y1,x2,y2,BLACK_BRUSH);
//                break;
//
//        }
//        ReleaseDC(hwnd, hdc);
//    }
    return 0;
}
