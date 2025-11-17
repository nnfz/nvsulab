#include <graphics.h>
#include <stdio.h>

#include "gfxmod.h"

int main() {
    initwindow(800, 600, "setka");

    setbkcolor(BLACK);
    cleardevice();

    int step = 40;

    drawSkewGrid(step);

    while (!kbhit()) {
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}
