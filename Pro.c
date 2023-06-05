#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawDDALine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xIncrement, yIncrement;
    float x = x1;
    float y = y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = dx / (float) steps;
    yIncrement = dy / (float) steps;

    putpixel(x, y, WHITE);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(x, y, WHITE);
    }
}

void drawBresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int p;

    if (dx >= dy) {
        p = 2 * dy - dx;
        x = x1 < x2 ? x1 : x2;
        y = x1 < x2 ? y1 : y2;

        putpixel(x, y, WHITE);

        for (int i = 0; i < dx; i++) {
            if (p >= 0) {
                y++;
                p += 2 * (dy - dx);
            } else {
                p += 2 * dy;
            }
            x++;
            putpixel(x, y, WHITE);
        }
    } else {
        p = 2 * dx - dy;
        x = y1 < y2 ? x1 : x2;
        y = y1 < y2 ? y1 : y2;

        putpixel(x, y, WHITE);

        for (int i = 0; i < dy; i++) {
            if (p >= 0) {
                x++;
                p += 2 * (dx - dy);
            } else {
                p += 2 * dx;
            }
            y++;
            putpixel(x, y, WHITE);
        }
   
