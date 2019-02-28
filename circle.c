#include <stdio.h>
#define SQR(x) (x) * (x)

struct circle {
    float x1, y1, rad1, x2, y2, rad2;
};

int main()

{
    float p1, p2, s1, s2;
    struct circle c;
    printf("Введите координаты окружности: \n");
    printf("Введите координаты по X1 и X2: \n");
    scanf("%e %e", &c.x1, &c.x2);
    printf("Введите координаты по Y1 и Y2: \n");
    scanf("%e %e", &c.y1, &c.y2);
    printf("Введите радиус первой окружности: ");
    scanf("%e", &c.rad1);
    printf("Введите радиус второй окружности: ");
    scanf("%e", &c.rad2);

    p1 = 2 * (3.14) * c.rad1;
    printf("Периметр первого круга : %.2f\n", p1);
    p2 = 2 * (3.14) * c.rad2;
    printf("Периметр второго круга : %.2f\n", p2);
    s1 = 3.14 * SQR(c.rad1);
    s2 = 3.14 * SQR(c.rad2);
    printf("Площадь первого круга : %.2f\n", s1);
    printf("Площадь второго круга : %.2f\n", s2);

    return 0;
}