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
    double maximum_weight;
    double boxes;
    double mean;
    double standard_deviation;

    scanf("%lf", &maximum_weight);
    scanf("%lf", &boxes);
    scanf("%lf", &mean);
    scanf("%lf", &standard_deviation);

    printf("%.4f\n", (1 + erf((maximum_weight - (boxes*mean)) / (sqrt(boxes) * standard_deviation * sqrt(2)))) / 2);

    return 0;
}
