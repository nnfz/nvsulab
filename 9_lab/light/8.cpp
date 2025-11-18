#include <graphics.h>
#include <stdio.h>

int main() {

    int maxx = 800;
    int maxy = 600;

    initwindow(maxx, maxy, "setka");

    setbkcolor(BLACK);
    cleardevice();

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

    getch();
    closegraph();
    return 0;
}
