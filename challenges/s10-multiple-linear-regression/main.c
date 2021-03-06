#include <stdio.h>

int main()
{
    int m;
    int n;
    int i;
    int j;
    int k;
    double X[100][10];
    long double XT[10][100];
    long double XT_X[10][10];
    long double XT_X_I[10][10];
    long double XT_X_I_XT[10][100];
    double Y[100];
    long double B[100];
    double f[10];
    long double AI[10][20];
    int q;
    double x;

    scanf("%d %d", &m, &n);
    for(i = 0; i < n; i++) {
        X[i][0] = 1;
        XT[0][i] = X[i][0];
        for(j = 1; j < (m+1); j++) {
            scanf("%lf", &(X[i][j]));
            XT[j][i] = X[i][j];
        }
        scanf("%lf", &Y[i]);
    }

    for(i = 0; i < (m+1); i++) {
        for(j = 0; j < (m+1); j++) {
            XT_X[i][j] = 0;
            for(k = 0; k < n; k++) {
                XT_X[i][j] += XT[i][k] * X[k][j];
            }
        }
    }

    for(i = 0; i < (m+1); i++) {
        for(j = 0; j < (m+1); j++) {
            AI[i][j] = XT_X[i][j];
        }
        for(j = (m+1); j < (m+1)*2; j++) {
            AI[i][j] = 0;
            if((i+(m+1)) == j) {
                AI[i][j] = 1;
            }
        }
    }

    for(i = 0; i < (m+1); i++) {
        if(AI[i][i] != 1) {
            x = AI[i][i];
            for(j = 0; j < (m+1)*2; j++) {
                AI[i][j] /= x;
            }
        }

        for(j = 0; j < (m+1); j++) {
            if(i == j) {
                continue;
            }

            if(AI[j][i] != 0) {
                x = AI[j][i] / AI[i][i];
                for(k = 0; k < (m+1)*2; k++) {
                    AI[j][k] -= AI[i][k] * x;
                }
            }
        }
    }

    for(i = 0; i < (m+1); i++) {
        for(j = 0; j < (m+1); j++) {
            XT_X_I[i][j] = AI[i][j+(m+1)];
        }
    }

    for(i = 0; i < (m+1); i++) {
        for(j = 0; j < n; j++) {
            XT_X_I_XT[i][j] = 0;
            for(k = 0; k < (m+1); k++) {
                XT_X_I_XT[i][j] += XT_X_I[i][k] * XT[k][j];
            }
        }
    }

    for(i = 0; i < (m+1); i++) {
        B[i] = 0;
        for(k = 0; k < n; k++) {
            B[i] += XT_X_I_XT[i][k] * Y[k];
        }
    }

    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        Y[i] = B[0];
        for(j = 1; j < (m+1); j++) {
            scanf("%lf", &f[j]);
            Y[i] += B[j] * f[j];
        }
        Y[i] += 0.0049;
        printf("%.2f\n", Y[i]);
    }

    return 0;
}
