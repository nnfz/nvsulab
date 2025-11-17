#include <graphics.h>
#include "gfxmod.h"

void drawSquare(int cx, int cy, int a)
{
    int h = a / 2;
    rectangle(cx - h, cy - h, cx + h, cy + h);
}

void drawText(int cx, int cy, char* txt)
{
    int w = textwidth(txt);
    int h = textheight(txt);
    outtextxy(cx - w/2, cy - h/2, (char*)txt);
}
