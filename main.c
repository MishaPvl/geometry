#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define L 200
#define MAX 1.7Е + 308
#define MIN 1.7Е - 308

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
        double pl = 2 * 3.14 * (c->rad);
        printf("%.2f\n", pl);
    }
    fclose(myfile);
    return 0;
}
int correct_data_circle(char* figure, Circle* c)
{
    int i = 7;
    int j = 0;
    int k = 0;
    char circle[7] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};

    for (k = 0; circle[k] != '\0'; k++) {
        if (figure[k] != circle[k]) {
            printf("Name Error\n");
            exit(1);
        }
    }
    for (j = 0; figure[i] != ' '; i++, j++) {
        if ((figure[i] < '0' || figure[i] > '9' || figure[i] == '-'
             || figure[i] == '+' || figure[i] == ' ')
            && figure[i] != '.') {
            printf("Incorrect coordinates\n");
            exit(1);
        }

        circle_str_x[j] = figure[i];
    }

    c->x = atof(circle_str_x);
    i++;

    for (j = 0; figure[i] != ','; i++, j++) {
        if ((figure[i] < '0' || figure[i] > '9' || figure[i] == '-'
             || figure[i] == '+' || figure[i] == ' ')
            && figure[i] != '.') {
            printf("Incorrect coordinates\n");
            exit(1);
        }
        circle_str_y[j] = figure[i];
    }
    i += 2;
    c->y = atof(circle_str_y);

    for (j = 0; figure[i] != ')'; i++, j++) {
        if ((figure[i] < '0' || figure[i] > '9' || figure[i] == '-'
             || figure[i] == '+' || figure[i] == ' ')
            && figure[i] != '.') {
            printf("Incorrect coordinates\n");
            exit(1);
        }
        circle_str_rad[j] = figure[i];
    }
    c->rad = atof(circle_str_rad);

    if (c->rad == 0) {
        printf("Incorrect radius set\n");
        return 1;
    }

    return 0;
}
