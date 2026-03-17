#include <stdio.h>
#include <stdlib.h>

// XOR encryption key
#define KEY 73

// Function to encrypt or decrypt a file
void processFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "rb");
    FILE *out = fopen(outputFile, "wb");

    if (in == NULL || out == NULL) {
        printf("Error: File open korte problem hochhe!\n");
        return;
    }

    unsigned char ch;
    while (fread(&ch, 1, 1, in) == 1) {
        ch = ch ^ KEY;  // XOR operation
        fwrite(&ch, 1, 1, out);
    }

    fclose(in);
    fclose(out);
}

int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("===== File Encryption Tool =====\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Input file name: ");
        scanf("%s", inputFile);
        printf("Output (encrypted) file name: ");
        scanf("%s", outputFile);
        processFile(inputFile, outputFile);
        printf("File successfully encrypted!\n");
    } 
    else if (choice == 2) {
        printf("Encrypted file name: ");
        scanf("%s", inputFile);
        printf("Output (decrypted) file name: ");
        scanf("%s", outputFile);
        processFile(inputFile, outputFile);
        printf("File successfully decrypted!\n");
    } 
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}