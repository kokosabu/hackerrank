#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int numerator;
    int denominator;
    int inspection;
    double p;
    double q;

    scanf("%d %d", &numerator, &denominator);
    scanf("%d", &inspection);
    
    p = (double)numerator / (double)denominator;
    q = 1.0 - p;

    printf("%.3f\n", pow(q, inspection-1) * p);
    return 0;
}

