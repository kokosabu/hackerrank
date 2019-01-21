#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int x;
    int n;
    double p;
    double q;
    int n_dash;
    int x_dash;
    int nx_dash;
    int i;
    int input1;
    int input2;
    double ans;

    scanf("%d", &input1);
    scanf("%d", &input2);

    n = input2;
    p = (double)input1 / 100.0;
    q = 1.0 - p;

    ans = 0;
    for(x = 3; x <= 10; x++) {
        n_dash = 1;
        for(i = 1; i <= n; i++) {
            n_dash *= i;
        }
        x_dash = 1;
        for(i = 1; i <= x; i++) {
            x_dash *= i;
        }
        nx_dash = 1;
        for (i = 1; i <= (n-x); i++) {
            nx_dash *= i;
        }
        ans += (n_dash / (x_dash*nx_dash)) * pow(p, x) * pow(q, n-x);
    }

    printf("%.3f\n", 1-ans);

    ans = 0;
    for(x = 2; x <= 10; x++) {
        n_dash = 1;
        for(i = 1; i <= n; i++) {
            n_dash *= i;
        }
        x_dash = 1;
        for(i = 1; i <= x; i++) {
            x_dash *= i;
        }
        nx_dash = 1;
        for (i = 1; i <= (n-x); i++) {
            nx_dash *= i;
        }
        ans += (n_dash / (x_dash*nx_dash)) * pow(p, x) * pow(q, n-x);
    }
    printf("%.3f\n", ans);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

