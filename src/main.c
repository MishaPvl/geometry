#include "correct_circle.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define L 200


int main()

{
    FILE* myfile;
    myfile = fopen("geometry.txt", "r");
    if (myfile == NULL) {
        printf("File not found\n");
        return 1;
    }

    Circle* c = (Circle*)malloc(sizeof(*c));


    while (!feof(myfile)) {
        fgets(figure, 200, myfile);
        if (feof(myfile))
            break;

        correct_circle(figure, c);
        printf("circle(%.2f %.2f, %.2f)\n", c->x, c->y, c->rad);
        double pr = 2 * 3.14 * (c->rad);
        double pl = 3.14 * (c->rad) * (c->rad);
        printf("Периметр равен : %.2f\n", pr);
        printf("Площадь равна : %.2f\n", pl);
    }
    fclose(myfile);
    return 0;
}
