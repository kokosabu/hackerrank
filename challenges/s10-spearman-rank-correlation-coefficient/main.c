#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct s {
    int order;
    int rank;
    double value;
};

int double_comp(const void *a, const void *b)
{
    double d = ((struct s *)a)->value - ((struct s *)b)->value;

    if(d > 0) {
        return 1;
    } else if(d == 0) {
        return 0;
    } else {
        return -1;
    }
}

int int_comp(const void *a, const void *b)
{
    return ((struct s *)a)->order - ((struct s *)b)->order;
}

int main()
{
    int n;
    struct s X[100];
    struct s Y[100];
    double d;
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%lf", &d);
        X[i].value = d;
        X[i].order = i+1;
    }
    for(i = 0; i < n; i++) {
        scanf("%lf", &d);
        Y[i].value = d;
        Y[i].order = i+1;
    }

    qsort(&X[0], n, sizeof(struct s), double_comp);
    qsort(&Y[0], n, sizeof(struct s), double_comp);

    for(i = 0; i < n; i++) {
        X[i].rank = i+1;
        Y[i].rank = i+1;
    }

    qsort(&X[0], n, sizeof(struct s), int_comp);
    qsort(&Y[0], n, sizeof(struct s), int_comp);

    d = 0;
    for(i = 0; i < n; i++) {
        d += pow(X[i].rank - Y[i].rank, 2);
    }
    printf("%.3f\n", 1.0 - ((6 * d) / (n * (n * n - 1))));

    return 0;
}

