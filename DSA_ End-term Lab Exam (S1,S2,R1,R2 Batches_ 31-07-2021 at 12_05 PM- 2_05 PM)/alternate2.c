#include <stdio.h>
#include <math.h>

double dst(int x1, int y1, int x2, int y2)
{
    double distance;
    double x = pow((x2-x1), 2);
    double y = pow((y2-y1), 2);
    distance = sqrt(x + y);
    return distance;
}



int main()
{
    printf("%.2f", dst(0, 0, 1, 1));
    return 0;
}