#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decToBinary(int decimal, FILE *outputFile)
{
    if (decimal == 0)
    {
        return;
    }
    decToBinary(decimal / 2, outputFile);
    fprintf(outputFile, "%d", decimal % 2);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *sourceFile = fopen(argv[2], "r");
    FILE *destinationFile = fopen(argv[3], "w");

    if (sourceFile == NULL || destinationFile == NULL)
    {
        perror("Error opening files");
        return 1;
    }

    int decimal;
    while (n > 0 && fscanf(sourceFile, "%d", &decimal) == 1)
    {
        fprintf(destinationFile, "The binary equivalent of %d is ", decimal);
        decToBinary(decimal, destinationFile);
        fprintf(destinationFile, "\n");
        n--;
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("Content of first 'n' decimal and their equivalent binary numbers.\n");

    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");

    return 0;
}
