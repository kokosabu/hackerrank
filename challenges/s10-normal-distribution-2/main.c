#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DX (0.000001)
#ifndef M_PI
#define M_PI (3.1415)
#endif

double erf(double z)
{
    double sum;
    double i;
    char flag;

    if(z < 0) {
        z *= -1;
        flag = 1;
    } else {
        flag = 0;
    }

    sum = 0;
    for(i = 0; i < z; i += DX) {
        sum += exp(-pow(i, 2)) * DX;
    }

    if(flag == 1) {
        sum *= -1;
    } else {
        ;
    }

    return (2.0 / sqrt(M_PI)) * sum;
}

int main()
{
    double mean;
    double standard_deviation;
    double q1;
    double q2_3;

    scanf("%lf %lf", &mean, &standard_deviation);
    scanf("%lf", &q1);
    scanf("%lf", &q2_3);

    printf("%.2f\n", (1.0 - (1 + erf((q1 - mean) / (standard_deviation * sqrt(2)))) / 2) * 100);
    printf("%.2f\n", (1.0 - (1 + erf((q2_3 - mean) / (standard_deviation * sqrt(2)))) / 2) * 100);
    printf("%.2f\n", (((1 + erf((q2_3 - mean) / (standard_deviation * sqrt(2)))) / 2)) * 100);

    return 0;
}
