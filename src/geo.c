#include "geo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 200

int circle_coord(char* string, Circle* cir, int num)
{
    char circle[7] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};

    for (int i = 0; circle[i] != '\0'; i++) {
        if (string[i] != circle[i]) {
            printf("%d.Name error\n", num);
            return 2;
        }
    }

    char coord_x[M];
    char coord_y[M];
    char coord_r[M];

    if (string[6] != '(') {
        printf("%d.Bracket error\n", num);
        return 3;
    }
    if (string[7] < '0' || string[7] > '9') {
        printf("%d.X coordinate error\n", num);
        return -1;
    }

    int i = 7;
    for (int j = 0; string[i] != ' '; i++, j++) {
        coord_x[j] = string[i];
    }

    (cir + num)->x = atof(coord_x);
    i++;

    if (string[i] < '0' || string[i] > '9') {
        printf("%d.String coord Error\n", num);
        return -1;
    }

    for (int j = 0; string[i] != ','; i++, j++) {
        if ((string[i] < '0' || string[i] > '9') && string[i] != '.') {
            printf("%d.Y coordinate error\n", num);
            return -1;
        }
        coord_y[j] = string[i];
    }
    i += 2;
    (cir + num)->y = atof(coord_y);
    if (string[i] < '0' || string[i] > '9') {
        printf("%d.String Error\n", num);
        return -1;
    }

    for (int j = 0; string[i] != ')'; i++, j++) {
        if (string[i] == '\0') {
            printf("%d.Bracket error\n", num);
            return -1;
        }
        if ((string[i] <= '0' || string[i] > '9') && string[i] != '.') {
            printf("%d.R coordinate error\n", num);
            return -1;
        }
        coord_r[j] = string[i];
    }
    (cir + num)->r = atof(coord_r);
    return 0;
}

void print_circle(Circle* cir, int v)
{
    int inter;
    for (int number = 1; number < v; number++) {
        printf("%d.circle(%.2f %.2f, %.2f)\n",
               (cir + number)->num,
               (cir + number)->x,
               (cir + number)->y,
               (cir + number)->r);
        printf("Perimeter = %.3f\n", circle_perimeter(cir, number));
        printf("Area = %.3f\n", circle_area(cir, number));
        printf("Intersection: \n");
        for (int j = 1; j < v; j++) {
            inter = circle_intersection(cir, number, j);
            if (inter) {
                printf("\t%d. circle\n", (cir + j)->num);
            }
        }
    }
}

double circle_perimeter(Circle* cir, int number)
{
    return (cir + number)->r * 2 * M_PI;
}

double circle_area(Circle* cir, int number)
{
    return (cir + number)->r * (cir + number)->r * M_PI;
}

int circle_intersection(Circle* cir, int number, int j)
{
    double t;
    t
            = sqrt((double)pow((cir + number)->x - (cir + j)->x, 2.00)
                   + (double)pow((cir + number)->y - (cir + j)->y, 2.00));
    if (t < (cir + number)->r + (cir + j)->r && (cir + number)->r < t + (cir + j)->r
        && (cir + j)->r < t + (cir + number)->r) {
        return 1;
    }
    return 0;
}