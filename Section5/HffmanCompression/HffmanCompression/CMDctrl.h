#pragma once

#define BLACK   0
#define BLUE    1
#define GREEN   2
#define LLBLUE  3
#define RED     4
#define PURPLE  5
#define YELLOW  6
#define WHITE   7
#define GRAY    8
#define LBLUE   9
#define LGREEN  10
#define LLLBLUE 11
#define LRED    12
#define LPURPLE 13
#define LYELLOW 14
#define LWHITE  15

void cls();
void setcolor(unsigned short ForeColor = WHITE, unsigned short BackColor = BLACK);
void PETC(int M = 1);