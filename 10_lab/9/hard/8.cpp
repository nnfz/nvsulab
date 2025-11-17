#include <graphics.h>
#include <math.h>
#include "gfxmod.h"

int main()
{
    initwindow(800, 600, "maxim");

    setbkcolor(WHITE);

    const int N = 5;
    int px[N] = {400, 400, 700, 150, 150};
    int py[N] = {100, 450, 150, 150, 550};

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

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

            setcolor(BLUE);
            drawText((int)x, (int)y, "MAXIM");

            delay(1);
            x += dx;
            y += dy;
        }
    }

    getch();
    closegraph();
    return 0;
}
