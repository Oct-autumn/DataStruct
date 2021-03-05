#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "CMDctrl.h"

void setcolor(unsigned short ForeColor, unsigned short BackColor)
{
    HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);   //获取控制台句柄
    SetConsoleTextAttribute(hdl, ForeColor + BackColor * 0x10);
}

void PETC(int M)
{
    printf("Press Enter to Continue...");
    for (int i = 1; i <= M; i++)
    {
        getchar();
    }    
}

void cls()
{
    system("cls");
}