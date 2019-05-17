#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <ctest.h>
#include <geo.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(test, perimeter)
{
    Circle cir = {2.1, 3.2, 4.0, 0};
    const int result = circle_perimeter(&cir, 0);
    const int expected = 25.1327;
    ASSERT_EQUAL(expected, result);
}

CTEST(test, name_error)
{
    Circle cir;
    char string[] = "triangle(1.1 1.2, 1.3)\0"; 
    const int result = circle_coord(string, &cir, 1);
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}


CTEST(test, area)
{
    Circle cir = {1.1, 1.2, 1.3, 0};
    const int result = circle_area(&cir, 0);
    const int expected = 5.309292;
    ASSERT_EQUAL(expected, result);
}



CTEST(test, check_intersection)
{
    Circle cir[3];
    cir[0].x = 1.1;
    cir[0].y = 1.2;
    cir[0].r = 1.3;
    cir[0].num = 0;
    cir[1].x = 2.1;
    cir[1].y = 2.2;
    cir[1].r = 0.2;
    cir[1].num = 1;
    cir[1].x = 2.1;
    cir[1].y = 2.0;
    cir[1].r = 0.2;
    cir[1].num = 1;

    const int result = circle_intersection(cir, 0, 1);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(test, check_intersection_wrong)
{
    Circle cir[2];
    cir[0].x = 1.1;
    cir[0].y = 1.2;
    cir[0].r = 1.3;
    cir[0].num = 0;
    cir[1].x = 5.1;
    cir[1].y = 5.2;
    cir[1].r = 1.2;
    cir[1].num = 1;
    const int result = circle_intersection(cir, 0, 1);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}


