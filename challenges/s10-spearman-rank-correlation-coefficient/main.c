#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    double X[100];
    double Y[100];
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%lf", &X[i]);
    }
    for(i = 0; i < n; i++) {
        scanf("%lf", &Y[i]);
    }

    return 0;
}

