#include "correct_circle.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define L 200

/*
typedef struct triangle {
    double a1;
    double a2;
    double b1;
    double b2;
    double r1;
    double r2;
    } Triangle;
 */

int main()

{
    FILE* myfile;
    myfile = fopen("geometry.txt", "r");
    if (myfile == NULL) {
        printf("File not found\n");
        return 1;
    }

    Circle* c = (Circle*)malloc(sizeof(*c));
    /*Triangle *t = (Triangle *)malloc(sizeof(*t));*/

    while (!feof(myfile)) {
        fgets(figure, 200, myfile);
        if (feof(myfile))
            break;

        correct_data_circle(figure, c);
        printf("circle(%.2f %.2f, %.2f)\n", c->x, c->y, c->rad);
        double pr = 2 * 3.14 * (c->rad);
        double pl = 3.14 * (c->rad) * (c->rad);
        printf("Периметр равен : %.2f\n", pr);
        printf("Площадь равна : %.2f\n", pl);
    }
    fclose(myfile);
    return 0;
}
