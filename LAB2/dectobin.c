#include <stdio.h>
#include <stdlib.h>

void decToBinary(int n, FILE *inputFile, FILE *outputFile) {
    if (n > 0) {
    
        int decimalNumber;
        fscanf(inputFile, "%d", &decimalNumber);

        int binaryNumber[32]; 
        int i = 0;
        while (decimalNumber > 0) {
            binaryNumber[i] = decimalNumber % 2;
            decimalNumber = decimalNumber / 2;
            i++;
        }
        for (int j = i - 1; j >= 0; j--) {
            fprintf(outputFile, "%d", binaryNumber[j]);
        }
        fprintf(outputFile, "\n");

        decToBinary(n - 1, inputFile, outputFile);
    }
}

int main() {
    int n;
    printf("Enter the number of decimal numbers to convert to binary: ");
    scanf("%d", &n);

    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    decToBinary(n, inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion complete. Binary numbers stored in output.txt.\n");

    return 0;
}
