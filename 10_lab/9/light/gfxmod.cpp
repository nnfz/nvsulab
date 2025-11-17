#include <graphics.h>
#include "gfxmod.h"

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

void drawSkewGrid(int step)
{
    int maxx = getmaxx();
    int maxy = getmaxy();

    int styles[] = { SOLID_LINE, DASHED_LINE, DOTTED_LINE, CENTER_LINE };
    int colors[] = { RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, WHITE };
    int nStyles = sizeof(styles) / sizeof(styles[0]);
    int nColors = sizeof(colors) / sizeof(colors[0]);

    int k = 0;

    // Наклонные линии одного наклона
    for (int d = -maxy; d <= maxx; d += step) {
        int style = styles[k % nStyles];
        int color = colors[k % nColors];
        k++;

        setlinestyle(style, 0, 1);
        setcolor(color);

        line(d, 0, d + maxy, maxy);
    }

    // Линии другого наклона
    for (int d = 0; d <= maxx + maxy; d += step) {
        int style = styles[k % nStyles];
        int color = colors[k % nColors];
        k++;

        setlinestyle(style, 0, 1);
        setcolor(color);

        line(d, 0, d - maxy, maxy);
    }
}
