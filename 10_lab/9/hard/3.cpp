#include <graphics.h>
#include <math.h>
#include "gfxmod.h"

int main()
{
    initwindow(800, 600, "zigzag");

    setbkcolor(WHITE);

    const int N = 5;
    int px[N] = {650, 500, 350, 200, 50};
    int py[N] = {250, 150, 250, 150, 250};

    int a = 40;

    for (int k = 0; k < N - 1; ++k)
    {
        double x  = px[k];
        double y  = py[k];
        double dx = px[k + 1] - px[k];
        double dy = py[k + 1] - py[k];

        int steps = (int)(fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy));

        dx /= steps;
        dy /= steps;

        for (int i = 0; i <= steps; ++i)
        {
            cleardevice();

            setlinestyle(SOLID_LINE, 0, 3);
            setcolor(BLUE);
            drawSquare((int)x, (int)y, a);

            delay(10);
            x += dx;
            y += dy;
        }
    }

    getch();
    closegraph();
    return 0;
}
