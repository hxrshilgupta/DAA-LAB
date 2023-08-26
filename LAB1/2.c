#include <stdio.h>

int main() {
    FILE *inputFile = fopen("input2.txt", "r");
    FILE *outputFile = fopen("output2.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("File error.\n");
        return 1;
    }

    int N;
    fscanf(inputFile, "%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    int prefixSum[N];
    prefixSum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    for (int i = 0; i < N; i++) {
        fprintf(outputFile, "%d ", prefixSum[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
