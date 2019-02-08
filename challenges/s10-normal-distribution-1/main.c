#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DX (0.0001)

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
    double q2_lower;
    double q2_upper;

    scanf("%lf %lf", &mean, &standard_deviation);
    scanf("%lf", &q1);
    scanf("%lf %lf", &q2_lower, &q2_upper);

    printf("%.3f\n", (1 + erf((q1 - mean) / (standard_deviation * sqrt(2)))) / 2);
    printf("%.3f\n", (1 + erf((q2_upper - mean) / (standard_deviation * sqrt(2)))) / 2 - (1 + erf((q2_lower - mean) / (standard_deviation * sqrt(2)))) / 2);

    return 0;
}
