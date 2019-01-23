#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double mean;
    int probability;
    int i;
    int k_dash;

    scanf("%lf", &mean);
    scanf("%d", &probability);

    k_dash = 1;
    for(i = 1; i <= probability; i++) {
        k_dash *= i;
    }

    printf("%.3f\n", (pow(mean, probability) * exp(-mean)) / k_dash);

    return 0;
}
