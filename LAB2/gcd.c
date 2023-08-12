#include <stdio.h>
#include <stdlib.h>

// Recursive function to find GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "r");
    FILE *destinationFile = fopen(argv[2], "w");

    if (sourceFile == NULL || destinationFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int num1, num2;
    int count = 0;

    while (fscanf(sourceFile, "%d %d", &num1, &num2) == 2) {
        // Calculate GCD using the recursive function
        int result = gcd(num1, num2);
        
        // Write the GCD result to the destination file
        fprintf(destinationFile, "%d\n", result);
        
        count++;
    }

    fclose(sourceFile);
    fclose(destinationFile);

    if (count >= 20) {
        printf("GCD calculation complete. Results stored in %s.\n", argv[2]);
    } else {
        printf("The source file must contain at least 20 pairs of numbers.\n");
        return 1;
    }

    return 0;
}
