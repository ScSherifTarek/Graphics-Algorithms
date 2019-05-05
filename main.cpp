#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <math.h>
#include<cmath>
#include <string.h>
#define PI 3.14159265359
// Add new popup menu
#define ADDPOPUPMENU(hmenu, string) \
	HMENU hSubMenu = CreatePopupMenu(); \
	AppendMenu(hmenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, string);

// Add a menu item
#define ADDMENUITEM(hmenu, ID, string) \
	AppendMenu(hSubMenu, MF_STRING, ID, string);

#define ADDMENUITEM(hmenu, ID, string) \
	AppendMenu(hSubMenu, MF_STRING, ID, string);
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
/*****************************************
/**********Line Functions**********************/

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

/*******************************************************/
/************Ellipse functions **************************/
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

/**************************************************************/
/******************Curve*****************************************/

class Vector_2points
{
public:

    double x, y;
    Vector_2points(double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
};

class Vector_4points
{
public :
    double v[4];

public:
    Vector_4points(double a = 0, double b = 0, double c = 0, double d = 0)
    {
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = d;
    }
    Vector_4points(double a[])
    {
        for (int i=0 ; i < 4 ; ++i)
        {
            v[i]= a[i] ;
        }
    }
    double atIndex(int i)
    {
        return v[i];
    }
};
class Matrix4X4
{
public:
    Vector_4points M[4];
public:
    Matrix4X4(double A[])
    {
        memcpy(M, A, 16 * sizeof(double));
    }
    Vector_4points atIndex(int i)
    {
        return M[i];
    }
};
Vector_4points MXV(Matrix4X4 Matrix, Vector_4points &b)
{
    Vector_4points result;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            result.v[i] += Matrix.M[i].v[j] * b.v[j];
    return result;
}

Vector_4points GetHermiteCoeff(double x1, double y1, double x2, double y2)
{
    double H[16] = {2, 1, -2, 1, -3, -2, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0};
    Matrix4X4 M(H);
    Vector_4points v(x1, y1, x2, y2);
    return  MXV(M , v) ;
}

double DotProduct(Vector_4points &a, Vector_4points &b)
{
    return a.v[0] * b.v[0] + a.v[1] * b.v[1] + a.v[2] * b.v[2] + a.v[3] * b.v[3];
}

void DrawCurveHermite(HDC hdc, Vector_2points &P0, Vector_2points &T0, Vector_2points &P1, Vector_2points &T1, int numpoints, COLORREF color)
{
    Vector_4points xc = GetHermiteCoeff(P0.x, T0.x, P1.x, T1.x);
    Vector_4points yc = GetHermiteCoeff(P0.y, T0.y, P1.y, T1.y);
    if (numpoints < 2)
        return;
    double steps = 1.0 / (numpoints - 1);
    for (double t = 0; t <= 1; t += steps)
    {
        Vector_4points vec;
        vec.v[3] = 1;
        for (int i = 2; i >= 0; i--)
            vec.v[i] = vec.v[i + 1] * t;
        int x = round(DotProduct(xc, vec));
        int y = round(DotProduct(xc, vec));
        SetPixel(hdc, x, y, color);
    }
}

void CurveHermite(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF color)
{
    int a1, b1, c1, d1 ,a2, b2, c2, d2;
    a1 = 2 * x1 + x2 - 2 * x3 + x4;
    a2 = 2 * y1 + y2 - 2 * y3 + y4;

    b1 = -3 * x1 - 2 * x2 + 3 * x3 - x4;
    b2 = -3 * y1 - 2 * y2 + 3 * y3 - y4;

    c1 = x2;
    c2 = y2;

    d1 = x1;
    d2 = y1;

    double x, y;
    for (double t = 0; t <= 1; t += 0.001)
    {
        x = a1 * pow(t,3) + b1 * pow(t,2) + c1 * (t) + d1;
        y = a2 * pow(t,3) + b2 * pow(t,2) + c2 * (t) + d2;
        SetPixel(hdc, round(x), round(y), color);
    }
}
/**********************************************************/

enum
{
	ID_FILE_EXIT,
	ID_Line_DDA,ID_Line_Midpoint,ID_Line_Parametric,
	ID_Circle_Cartesian,ID_Circle_Polar,ID_Circle_IterativePolar,ID_Circle_MidPoint,
	ID_Curve_FirstDegree,ID_Curve_SecondDegree,ID_Curve_ThirdHermit,ID_Curve_ThirdBezier,ID_Curve_Splines,
	ID_Filling,ID_FloodFilling,
	ID_ClippingP,ID_ClippingL,
	ID_Save,ID_Reload,ID_ChangeColorWhite,ID_ChangeColorDefault
};
void CreateMainMenu(HWND hwnd)
{
    HMENU hmenu = CreateMenu();

	ADDPOPUPMENU(hmenu, "&Menu");
	ADDMENUITEM(hmenu, ID_ChangeColorWhite,"&Change Background Color: White");
	ADDMENUITEM(hmenu, ID_ChangeColorDefault,"&Change Background Color: Default");
	ADDMENUITEM(hmenu, ID_Save, "&Save Current Draw");
	ADDMENUITEM(hmenu, ID_Reload, "&Load Previous Draw");

	ADDMENUITEM(hmenu, NULL, NULL);

	ADDMENUITEM(hmenu, ID_Line_DDA, "&Line: DDA");
	ADDMENUITEM(hmenu, ID_Line_Midpoint, "&Line: MidPoint");
	//ADDMENUITEM(hmenu, ID_Line_Parametric, "&Line: Parametric");

	ADDMENUITEM(hmenu, NULL, NULL);

	ADDMENUITEM(hmenu, ID_Circle_Cartesian, "&Circle: Cartesian");
	ADDMENUITEM(hmenu, ID_Circle_Polar, "&Circle: Polar");
	//ADDMENUITEM(hmenu, ID_Circle_IterativePolar, "&Circle: IterativePolar");
	ADDMENUITEM(hmenu, ID_Circle_MidPoint, "&Circle: MidPoint");

	ADDMENUITEM(hmenu, NULL, NULL);

	//ADDMENUITEM(hmenu, ID_Curve_FirstDegree, "&Curve: First Degree");
	//ADDMENUITEM(hmenu, ID_Curve_SecondDegree, "&Curve: Second Degree");
	ADDMENUITEM(hmenu, ID_Curve_ThirdHermit, "&Curve: Hermit");
	ADDMENUITEM(hmenu, ID_Curve_ThirdBezier, "&Curve: Bezier");
	//ADDMENUITEM(hmenu, ID_Curve_Splines, "&Curve: Splines");

	ADDMENUITEM(hmenu, NULL, NULL);

	//ADDMENUITEM(hmenu, ID_Filling, "&Filling: Convex & NonConvex");
	ADDMENUITEM(hmenu, ID_FloodFilling, "&Filling: Flood Fill");

	ADDMENUITEM(hmenu, NULL, NULL);

	ADDMENUITEM(hmenu, ID_ClippingP, "&Clipping: Polygon Clipping Polygon");
    ADDMENUITEM(hmenu, ID_ClippingL, "&Clipping: Polygon Clipping Line");
	ADDMENUITEM(hmenu, NULL, NULL);
	ADDMENUITEM(hmenu, ID_FILE_EXIT, "&Exit");

    SetMenu(hwnd, hmenu);
}

COLORREF bkgndcolor=RGB(211,211,211);
COLORREF Fcolor=RGB(100,80,100);
COLORREF Dcolor=RGB(100,80,100);

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    HDC  hdc;
    static int x,y,xs,ys,xe,ye,r,x1,y1,x2,y2,x3,y3,x4,y4;
    static bool line=false,first=true;
    static int flag=0;
    static int algoID =0 ;
    POINT p[100];
    static int flag2=0;
    POINT p2[100];
    Vector_2points v[100];
    RECT rect;
    PAINTSTRUCT ps;
    hdc = GetDC(hwnd);
    GetClientRect(hwnd,&rect);

    switch (message)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
			return 0;

		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
//				case ID_FILE_EXIT:
//					PostQuitMessage(0);
//					break;
//
//                case ID_ChangeColorWhite:
//                    Dcolor=RGB(0,0,0);
//                    ChangeBkGnd(hwnd);
//                    break;
//
//                case ID_ChangeColorDefault:
//                    Dcolor=RGB(255,255,255);
//                    defBkGnd(hwnd);
//                    break;
//
//                case ID_Save:
//                    SaveScreen(hdc,"screen.txt",rect);
//					break;
//
//                case ID_Reload:
//                    LoadScreen(hdc,"screen.txt",rect);
//					break;
//
//				case ID_Line_DDA:
//                    algo="lineD";
//					//MessageBox(hwnd, "Hello!", "Message", MB_ICONINFORMATION);
//					break;
//
//
//                case ID_Line_Midpoint:
//                    algo="lineM";
//                    break;
//
//
//
//                case ID_Circle_Cartesian:
//                    algo="circleC";
//                    break;
//
//
//                case ID_Circle_Polar:
//                    algo="circleP";
//                    break;
//
//
//
//
//                case ID_Circle_MidPoint:
//                    algo="circleM";
//                    break;



               // case ID_Curve_ThirdHermit:
                    algoID=5;
                    break;


                case ID_Curve_ThirdBezier:
                    algoID=6;
                    break;




//                case ID_ClippingP:
//                    algo="clippingP";
//                    DrawLineDDA(hdc,rect.left+100,rect.top+100,rect.left+100,rect.bottom-100,Dcolor);
//                    DrawLineDDA(hdc,rect.right-100,rect.top+100,rect.right-100,rect.bottom-100,Dcolor);
//                    DrawLineDDA(hdc,rect.left+100,rect.top+100,rect.right-100,rect.top+100,Dcolor);
//                    DrawLineDDA(hdc,rect.left+100,rect.bottom-100,rect.right-100,rect.bottom-100,Dcolor);
//                    break;
//
//                case ID_ClippingL:
//                    algo="clippingL";
//                    DrawLineDDA(hdc,rect.left+100,rect.top+100,rect.left+100,rect.bottom-100,Dcolor);
//                    DrawLineDDA(hdc,rect.right-100,rect.top+100,rect.right-100,rect.bottom-100,Dcolor);
//                    DrawLineDDA(hdc,rect.left+100,rect.top+100,rect.right-100,rect.top+100,Dcolor);
//                    DrawLineDDA(hdc,rect.left+100,rect.bottom-100,rect.right-100,rect.bottom-100,Dcolor);
//                    break;
//
//
//                case ID_Filling:
//                    algo="filling";
//                    break;
//
//                case ID_FloodFilling:
//                    algo="flood";
//                    break;

			}

		} break;

		case WM_ERASEBKGND:
              HPEN pen;
              HBRUSH brush;

              pen=CreatePen(PS_SOLID, 1, bkgndcolor);
              brush=CreateSolidBrush(bkgndcolor);
              SelectObject((HDC)wParam, pen);
              SelectObject((HDC)wParam, brush);

              GetClientRect(hwnd, &rect);

              Rectangle((HDC)wParam, rect.left, rect.top, rect.right, rect.bottom);
		break;

        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
		break;

        case WM_LBUTTONDOWN:
//            if(algoID=="lineD"){
//                if(first){
//                    xs = LOWORD(lParam);
//                    ys = HIWORD(lParam);
//                    first=false;
//                }else{
//                    xe = LOWORD(lParam);
//                    ye = HIWORD(lParam);
//                    first=true;
//                    DrawLineDDA(hdc,xs,ys,xe,ye,Dcolor);
//                }
//            }
//               else if(algo=="lineM"){
//                if(first){
//                    xs = LOWORD(lParam);
//                    ys = HIWORD(lParam);
//                    first=false;
//                }else{
//                    xe = LOWORD(lParam);
//                    ye = HIWORD(lParam);
//                    first=true;
//                    DrawLineMidPoint(hdc,xs,ys,xe,ye);
//                }
//            }else if(algo=="circleC"){
//                if(first){
//                    xs = LOWORD(lParam);
//                    ys = HIWORD(lParam);
//                    first=false;
//                }else{
//                    xe = LOWORD(lParam);
//                    ye = HIWORD(lParam);
//                    first=true;
//                    r=sqrt((xe-xs)*(xe-xs)+(ye-ys)*(ye-ys));
//                    DrawCircleCartesian(hdc,xs,ys,r,Dcolor);
//                }
//            }else if(algo=="circleP"){
//                if(first){
//                    xs = LOWORD(lParam);
//                    ys = HIWORD(lParam);
//                    first=false;
//                }else{
//                    xe = LOWORD(lParam);
//                    ye = HIWORD(lParam);
//                    first=true;
//                    r=sqrt((xe-xs)*(xe-xs)+(ye-ys)*(ye-ys));
//                    DrawCirclePolar(hdc,xs,ys,r,Dcolor);
//                }
//            }
//          else if(algo=="circleM"){
//                if(first){
//                    xs = LOWORD(lParam);
//                    ys = HIWORD(lParam);
//                    first=false;
//                }else{
//                    xe = LOWORD(lParam);
//                    ye = HIWORD(lParam);
//                    first=true;
//                    r=sqrt((xe-xs)*(xe-xs)+(ye-ys)*(ye-ys));
//                    DrawCircleMidPoint(hdc,xs,ys,r,Dcolor);
//                }
//            }
//


             if(algoID==5){
                if(flag==0){
                    x1 = LOWORD(lParam);
                    y1 = HIWORD(lParam);
                    flag=1;
                }else if (flag==1){
                    x2 = LOWORD(lParam);
                    y2 = HIWORD(lParam);
                    flag=2;
                }else if (flag==2){
                    x3 = LOWORD(lParam);
                    y3 = HIWORD(lParam);
                    flag=3;
                }else if (flag==3){
                    x4 = LOWORD(lParam);
                    y4 = HIWORD(lParam);
                    CurveHermite(hdc,x1,y1,x2,y2,x3,y3,x4,y4,Dcolor);
                    flag=0;
                }
            }else if(algoID==6){
                if(flag==0){
                    x1 = LOWORD(lParam);
                    y1 = HIWORD(lParam);
                    flag=1;
                }else if (flag==1){
                    x2 = LOWORD(lParam);
                    y2 = HIWORD(lParam);
                    flag=2;
                }else if (flag==2){
                    x3 = LOWORD(lParam);
                    y3 = HIWORD(lParam);
                    flag=3;
                }else if (flag==3){
                    x4 = LOWORD(lParam);
                    y4 = HIWORD(lParam);
                   // DrawCurveBezier(hdc,x1,y1,x2,y2,x3,y3,x4,y4,Dcolor);
                    flag=0;
                }
            }

//            else if(algo == "flood"){
//                x = LOWORD(lParam);
//                y = HIWORD(lParam);
//                NRFloodFill(hdc,x,y,Dcolor,Fcolor);
//            }else if(algo=="clipping"){
//                x = LOWORD(lParam);
//                y = HIWORD(lParam);
//                p2[flag2].x=x;
//                p2[flag2].y=y;
//                flag2++;
//            }
//            break;
//
//            case WM_LBUTTONDBLCLK:
//             if(algo=="clippingL"){
//
//                x = LOWORD(lParam);
//                y = HIWORD(lParam);
//                p2[flag2].x=x;
//                p2[flag2].y=y;
//                flag2++;
//               // CohenSuth(hdc,p2,flag2,rect.left+100,rect.top+100,rect.right-100,rect.bottom-100);
////                CohenSuth(hdc,xs,ys,xe,ye,xc,yc,x,y);
//
//                flag2=0;
//            }
//             if(algo=="clippingP"){
//
//                x = LOWORD(lParam);
//                y = HIWORD(lParam);
//                p2[flag2].x=x;
//                p2[flag2].y=y;
//                flag2++;
//                PolygonClip(hdc,p2,flag2,rect.left+100,rect.top+100,rect.right-100,rect.bottom-100);
//                flag2=0;
//            }

            break;

		default:
			return DefWindowProc(hwnd,message,wParam,lParam);
	}

    return 0;
}
//LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//
//
///// line
////    static int x1,y1,x2,y2;
//
///// ellipse
//    static int counter = 3, a, b, xc, yc;
//
//    HDC hdc;
//    switch (message)                  /* handle the messages */
//    {
//        case WM_DESTROY:
//            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
//            break;
//        case WM_LBUTTONDOWN:
//            switch(counter)
//            {
//            case 3:
//                xc =LOWORD(lParam);
//                yc= HIWORD(lParam);
//                break;
//
//            case 2:
//                a = abs(xc-LOWORD(lParam));
//                break;
//
//            case 1:
//                b = abs(yc-HIWORD(lParam));
//                hdc = GetDC(hwnd);
//                ellipseMidPoint(hdc,xc,yc,a,b,BLACK_BRUSH);
//                ReleaseDC(hwnd, hdc);
//
//            default:
//                counter=4;
//            }
//            counter--;
//            break;
//
/////Line
////        case WM_LBUTTONDOWN:
////            x1 = LOWORD(lParam);
////            y1 = HIWORD(lParam);
////            break;
////        case WM_LBUTTONUP:
////            x2 =LOWORD(lParam);
////            y2= HIWORD(lParam);
////            hdc = GetDC(hwnd);
////            lineDDA(hdc,x1,y1,x2,y2,BLACK_BRUSH);
////            ReleaseDC(hwnd, hdc);
////            break;
//
//        default:                      /* for messages that we don't deal with */
//            return DefWindowProc (hwnd, message, wParam, lParam);
//    }
////    if(choosed)
////    {
////        int c;
////        std::cin>>c;
////
////        HDC hdc = GetDC(hwnd);
////        switch(c)
////        {
////            case 0:
////                lineDDA(hdc,x1,y1,x2,y2,BLACK_BRUSH);
////                break;
////
////        }
////        ReleaseDC(hwnd, hdc);
////    }
//    return 0;
//}
