#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decToBinary(int decimal, FILE *outputFile) {
    if (decimal == 0) {
        return;
    }

    decToBinary(decimal / 2, outputFile);
    fprintf(outputFile, "%d", decimal % 2);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <decimal1> <decimal2> ... <decimalN>\n", argv[0]);
        return 1;
    }

    int n = argc - 1; // Number of decimal values provided
    FILE *destinationFile = stdout; // Output to the standard output

    int decimal;
    for (int i = 1; i <= n; i++) {
        decimal = atoi(argv[i]);
        fprintf(destinationFile, "The binary equivalent of %d is ", decimal);
        decToBinary(decimal, destinationFile);
        fprintf(destinationFile, "\n");
    }

    printf("Content of first 'n' decimal and their equivalent binary numbers.\n");

    return 0;
}
