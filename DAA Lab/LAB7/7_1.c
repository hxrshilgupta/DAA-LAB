#include <stdio.h>
#include <limits.h>

void printOptimalParenthesis(int i, int j, int n, int *s) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(i, *((s + i * n) + j), n, s);
        printOptimalParenthesis(*((s + i * n) + j) + 1, j, n, s);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("M Table:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j >= i) {
                printf("%d\t", m[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    printf("S Table:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j > i) {
                printf("%d\t", s[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    printOptimalParenthesis(1, n - 1, n, (int *)s);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n - 1]);
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter dimensions (row and column) for each matrix:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i], &p[i + 1]);
    }

    matrixChainOrder(p, n + 1);

    return 0;
}