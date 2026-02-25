#include "pch.h"
#include "framework.h"

#define MAX_DISP    100

extern BOOL bDrag;
extern int xStartPos, yStartPos;

void ShowHello(HWND hwnd, HDC hdc)
{
    // 디바이스 컨텍스트 획득

    LPCWSTR lpszMessage = L"안녕하세요";
    int len = wcslen(lpszMessage);

    RECT rt;
    ::GetClientRect(hwnd, &rt);                     // rt 구조체에 윈도우의 크기를 돌려줌
    int width = rt.right - rt.left;                 // 윈도우의 내부 넓이
    int height = rt.bottom - rt.top;                // 윈도우의 내부 높이

    int center_x = width / 2;
    int center_y = height / 2;

    ::TextOutW(hdc, center_x - 50, center_y, lpszMessage, len);        // 디바이스 컨택스트에 문자열 출력, 위치, 길이. TextOutA; only Eng, TextOutW; +Kor

}

void ShowRectangle(HWND hwnd, HDC hdc)
{
    // 펜 오브젝트 생성
    HPEN hPen = ::CreatePen(PS_SOLID, 3, RGB(0, 0, 128));
    // 브러시 오브젝트 생성
    HBRUSH hBrush = ::CreateSolidBrush(RGB(128, 64, 64));
    
    // DC에 그릴 오브젝트 선택
    HGDIOBJ hOldPen = ::SelectObject(hdc, hPen);
    HGDIOBJ hOldBrush = ::SelectObject(hdc, hBrush);

    // 사각형 그림 (10,10) 위치에 100x100 크기 사각형 그림
    ::Rectangle(hdc, 10, 10, 110, 110);
    // 펜과 브러시 사용 후 초기화
    ::SelectObject(hdc, hOldPen);
    ::SelectObject(hdc, hOldBrush);
    ::DeleteObject(hPen);
    ::DeleteObject(hBrush);
}

void ShowMouseLocation(HWND hWnd, HDC hdc, int xPos, int yPos)
{
    
    //HDC hdc = ::GetDC(hWnd);

    if (!bDrag)
        return;

    RECT rt;
    ::GetClientRect(hWnd, &rt);
    int cx = rt.right - rt.left;
    int cy = rt.bottom - rt.top;

    // 메모리 DC 생성
    HDC hMemDC = ::CreateCompatibleDC(hdc);
    HBITMAP hBmp = ::CreateCompatibleBitmap(hdc, cx, cy);   // 도화지 생성
    HGDIOBJ hOldBmp = ::SelectObject(hMemDC, hBmp);         // 도화지 적용

    WCHAR strOut[MAX_DISP] = { 0 };
    wsprintfW(strOut, L"X 좌표: %d", xPos);
    ::TextOutW(hdc, 10, 10, strOut, wcslen(strOut));

    wsprintfW(strOut, L"Y 좌표: %d", yPos);
    ::TextOutW(hdc, 10, 30, strOut, wcslen(strOut));

    // 두꺼운 선 그리기
    HPEN hLine = ::CreatePen(PS_SOLID, 100, RGB(0, 0, 128));
    HGDIOBJ hOldLine = ::SelectObject(hdc, hLine);


    // 시작점을 이동시킴
    ::MoveToEx(hdc, xStartPos, yStartPos, NULL);
    ::LineTo(hdc, xPos, yPos);


    ::SelectObject(hdc, hOldLine);
    ::DeleteObject(hOldLine);

    //::ReleaseDC(hWnd,hdc);
}
