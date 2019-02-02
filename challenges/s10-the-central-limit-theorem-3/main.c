#include <stdio.h>
#include <math.h>

int main()
{
    double sample_size;
    double mean;
    double standard_deviation;
    double distribution;
    double z;
    double A;
    double B;

    scanf("%lf", &sample_size);
    scanf("%lf", &mean);
    scanf("%lf", &standard_deviation);
    scanf("%lf", &distribution);
    scanf("%lf", &z);

    A = mean - (z * standard_deviation / sqrt(sample_size));
    B = mean + (z * standard_deviation / sqrt(sample_size));
    printf("%.2f\n", A);
    printf("%.2f\n", B);

    return 0;
}
