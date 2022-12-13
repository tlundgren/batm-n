// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
extern "C" void TimeSlow();
extern "C" void TimeNormal();


// Every checkCycle check if time bar is present in the screen.
// If present, slow time. Else, normalize time. 
DWORD WINAPI BotTime( LPVOID lpParam ) 
{
    DWORD checkCycle = 4500; // 4.5 secs between checks
    COLORREF colorBarTime = 0x001116; // 0x00161100 as per a photo app
    COLORREF colorSampleLeft;
    COLORREF colorSampleRight;
    int xSampleLeft = 495;
    int ySampleLeft = 901;
    int xSampleRight = 1420;
    int ySampleRight = 901;
    HDC hdc = GetDC(NULL);
    if (hdc == NULL)
        return 0;
    while (true)
    {
        colorSampleLeft = GetPixel(hdc, xSampleLeft, ySampleLeft);
        colorSampleRight = GetPixel(hdc, xSampleRight, ySampleRight);
        if ((colorSampleLeft == colorBarTime) && (colorSampleRight == colorBarTime))
        {
            TimeSlow();
        }
        else
        {
            TimeNormal();
        }
        Sleep(checkCycle);
    }
    ReleaseDC(NULL, hdc);
    return 1;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread( NULL, 0, &BotTime, NULL, 0, NULL );
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

