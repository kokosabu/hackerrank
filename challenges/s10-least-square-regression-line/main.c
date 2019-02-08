#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double x[5];
    double y[5];
    int i;
    int n;
    double sum_x;
    double sum_y;
    double mean_x;
    double mean_y;
    double sum_xx;
    double sum_xy;
    double b;
    double a;

    n = 5;

    sum_x = 0;
    sum_y = 0;
    sum_xx = 0;
    sum_xy = 0;
    for(i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
        sum_x += x[i];
        sum_y += y[i];
        sum_xx += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    mean_x = sum_x / n;
    mean_y = sum_y / n;

    b = ((n * sum_xy) - (sum_x * sum_y)) / ((5 * sum_xx) - pow(sum_x, 2));
    a = mean_y - (b * mean_x);

    printf("%.3f\n", a + (b * 80));

    return 0;
}

