#ifndef CORRECT_CIRCLE_H
#define CORRECT_CIRCLE_H
#define L 200

typedef struct circle {
    double x;
    double y;
    double rad;
} Circle;

/*typedef struct triangle {
    double a1;
    double a2;
    double b1;
    double b2;
    double r1;
    double r2;
    } Triangle;*/
int correct_data_circle();
char circle_str_x[L];
char circle_str_y[L];
char circle_str_rad[L];
char figure[L];

#endif
