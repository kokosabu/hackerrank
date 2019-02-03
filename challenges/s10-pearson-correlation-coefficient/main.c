#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define N (500)

int main()
{
    int n;
    double X[N];
    double Y[N];
    double mean_x;
    double std_x;
    double mean_y;
    double std_y;
    double sum;
    int i;

    scanf("%d", &n);
    sum = 0;
    for(i = 0; i < n; i++) {
        scanf("%lf", &X[i]);
        sum += X[i];
    }
    mean_x = sum / n;
    sum = 0;
    for(i = 0; i < n; i++) {
        sum += pow(X[i], 2) - pow(mean_x, 2);
    }
    std_x = sqrt(sum / n);
    sum = 0;
    for(i = 0; i < n; i++) {
        scanf("%lf", &Y[i]);
        sum += Y[i];
    }
    mean_y = sum / n;
    sum = 0;
    for(i = 0; i < n; i++) {
        sum += pow(Y[i], 2) - pow(mean_y, 2);
    }
    std_y = sqrt(sum / n);


    sum = 0;
    for(i = 0; i < n; i++) {
        sum += (X[i] - mean_x) * (Y[i] - mean_y);
    }
    printf("%.3f\n", sum / (n * std_x * std_y));

    return 0;
}

