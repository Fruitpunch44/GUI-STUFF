#include<stdio.h>
#include<windows.h>
#include<winuser.h>
LRESULT CALLBACK WindowProc(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg){
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0; 
        default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }  }

LRESULT CALLBACK WindowProc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp);

int WINAPI WinMain(HINSTANCE hINSTANCE, HINSTANCE hPrevinstance,LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSW wc ={0};//define the windows class
    wc.hbrBackground=(HBRUSH)COLOR_WINDOW;//DEFINES THE BACKGROUND OF THE WINDOW
    wc.hCursor =LoadCursor(NULL,IDC_ARROW);//
    wc.hInstance=hINSTANCE;
    wc.lpszClassName="MyClass";
    wc.lpfnWndProc=WindowProc;

    if (!RegisterClassW(&wc))
    return -1;
CreateWindowW("MyClass",//
"MY WINDOW BITCH",//caption name of window
WS_OVERLAPPEDWINDOW|WS_VISIBLE,//type of windwow to be displayed
100,100, //position of the window on screen
1320,500, //size of the window
NULL,
NULL,
hINSTANCE,
NULL);

MSG msg ={0};	
while(GetMessage(&msg,NULL,NULL,NULL))
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
    return 0;

}

  
 