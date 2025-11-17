#include <graphics.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initwindow(800, 600, "setka");

    setbkcolor(BLACK);
    cleardevice();

    int maxx = getmaxx();
    int maxy = getmaxy();

    int step = 40;

    int styles[] = { SOLID_LINE, DASHED_LINE, DOTTED_LINE, CENTER_LINE };
    int colors[] = { RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, WHITE };
    int nStyles = sizeof(styles) / sizeof(styles[0]);
    int nColors = sizeof(colors) / sizeof(colors[0]);

    int k = 0;

    for (int d = -maxy; d <= maxx; d += step) {
        int style = styles[k % nStyles];
        int color = colors[k % nColors];
        k++;

        setlinestyle(style, 0, 1);
        setcolor(color);

        line(d, 0, d + maxy, maxy);
    }

    for (int d = 0; d <= maxx + maxy; d += step) {
        int style = styles[k % nStyles];
        int color = colors[k % nColors];
        k++;

        setlinestyle(style, 0, 1);
        setcolor(color);

        line(d, 0, d - maxy, maxy);
    }

    outtextxy(10, 10, (char*)"Kosaya setka: raznye cveta i stili");

    while (!kbhit()) {
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}
