#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double A;
    double B;

    scanf("%lf %lf", &A, &B);

    printf("%.3f\n", 160 + 40 * (A + pow(A, 2)));
    printf("%.3f\n", 128 + 40 * (B + pow(B, 2)));

    return 0;
}
