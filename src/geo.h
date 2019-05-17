#ifndef GEO_H
#define GEO_H

#define N 200

typedef struct {
    double x;
    double y;
    double r;
    double z;
    int num;
} Circle;

void circle(Circle* cir, int col);
int circle_coord(char* c, Circle* cir, int num);
double circle_perimeter(Circle* cir, int i);
double circle_area(Circle* cir, int i);
int circle_intersection(Circle* cir, int i, int j);
#endif