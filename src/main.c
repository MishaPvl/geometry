#include "geo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char figure[N]; //c

    FILE* coord;
    coord = fopen("coord.txt", "r");

    if (coord == NULL) {
        printf("File not found\n");
        return -1;
    }

    Circle* cir = (Circle*)malloc(sizeof(Circle) * N);

    int fl = 0;

    while (!feof(coord)) {
        fgets(figure, N, coord);
        if (strcmp(figure, "\n\0") == 0) {
            continue;
        }

        fl++;
        (cir + fl)->num = fl;

        if (circle_coord(figure, cir, fl) == -1) {
            fl--;
            continue;
        }
    }
    circle(cir, fl);
    fclose(coord);

    return 0;
}