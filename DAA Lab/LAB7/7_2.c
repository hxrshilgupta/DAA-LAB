#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printLCS(char X[], char Y[], int m, int n) {
    int lcs[m + 1][n + 1];
    int i, j;

    // Build the LCS matrix
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    // Find the LCS length
    int length = lcs[m][n];

    // Initialize LCS string
    char lcsStr[length + 1];
    lcsStr[length] = '\0';

    // Backtrack to find the LCS
    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr[length - 1] = X[i - 1];
            i--;
            j--;
            length--;
        } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LCS: %s\n", lcsStr);
   printf("LCS Length: %zu\n", strlen(lcsStr));

}

int main() {
    char X[100], Y[100];

    printf("Enter the first string into an array: ");
    scanf("%s", X);

    printf("Enter the second string into an array: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    printLCS(X, Y, m, n);
    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
    return 0;
}