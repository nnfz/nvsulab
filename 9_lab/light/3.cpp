#include <graphics.h>
#include <stdio.h>

void drawRing(int x, int y, int r,
              int lineStyle, int lineWidth, int lineColor,
              int fillPattern, int fillColor)
{
    setlinestyle(lineStyle, 0, lineWidth);
    setcolor(lineColor);
    circle(x, y, r);

    setfillstyle(fillPattern, fillColor);
    floodfill(x, y, lineColor);
}

int main() {
    initwindow(800, 600, "flag");

    setbkcolor(WHITE);
    cleardevice();

    int r      = 60;
    int dx     = 140;
    int x0     = 200;
    int yTop   = 250;
    int yBottom= 330;


    drawRing(x0,          yTop,    r,
             SOLID_LINE,  4,       BLUE,
             SOLID_FILL,  LIGHTBLUE);

    drawRing(x0 + dx,     yTop,    r,
             SOLID_LINE,  4,       BLACK,
             HATCH_FILL,  DARKGRAY);

    drawRing(x0 + 2*dx,   yTop,    r,
             SOLID_LINE,  4,       RED,
             SLASH_FILL,  LIGHTRED);

    drawRing(x0 + dx/2,   yBottom, r,
             SOLID_LINE,  4,       YELLOW,
             CLOSE_DOT_FILL, YELLOW);

    drawRing(x0 + dx + dx/2, yBottom, r,
             SOLID_LINE,  4,       GREEN,
             XHATCH_FILL, LIGHTGREEN);

    while (!kbhit()) {
        delay(10);
    }
    getch();

    closegraph();
    return 0;
}
