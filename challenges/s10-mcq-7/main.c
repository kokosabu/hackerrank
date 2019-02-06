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

    // 3x + 4y + 8 = 0
    // 4x + 3y + 7 = 0
    // -x + y + 1 = 0
    // -x = -y - 1
    // x = y + 1
    //
    // (3y + 3) + 4y + 8 = 0
    // 7y + 11 = 0
    // y = -11/7
    //
    // 12x + 16y + 32 = 0
    // 12x + 9y + 21 = 0
    // 7y + 11 = 0
    // y = -7/11
    // 4x + -21/11 + 7 = 0
    // 4x = 56/11
    // x = 14/11

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

