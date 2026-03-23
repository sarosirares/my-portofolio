#include <stdio.h>
#include <stdlib.h>

void replaceLine(const char *filePath, int lineNumber, const char *newText) {
    FILE *fileIn, *fileOut;
    char buffer[1024];
    char tempFilePath[] = "temp.txt";

    fileIn = fopen(filePath, "r");
    if (fileIn == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    fileOut = fopen(tempFilePath, "w");
    if (fileOut == NULL) {
        perror("Error creating temporary file");
        fclose(fileIn);
        exit(EXIT_FAILURE);
    }

    int currentLine = 0;
    while (fgets(buffer, sizeof(buffer), fileIn) != NULL) {
        currentLine++;
        if (currentLine == lineNumber) {
            fprintf(fileOut, "%s\n", newText);
        } else {
            fprintf(fileOut, "%s", buffer);
        }
    }

    fclose(fileIn);
    fclose(fileOut);

    remove(filePath);
    rename(tempFilePath, filePath);

    printf("Line %d replaced successfully.\n", lineNumber);
}

void deleteLine(const char *filePath, int lineNumber) {
    FILE *fileIn, *fileOut;
    char buffer[1024];
    char tempFilePath[] = "temp.txt";

    fileIn = fopen(filePath, "r");
    if (fileIn == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    fileOut = fopen(tempFilePath, "w");
    if (fileOut == NULL) {
        perror("Error creating temporary file");
        fclose(fileIn);
        exit(EXIT_FAILURE);
    }

    int currentLine = 0;
    while (fgets(buffer, sizeof(buffer), fileIn) != NULL) {
        currentLine++;
        if (currentLine != lineNumber) {
            fprintf(fileOut, "%s", buffer);
        }
    }

    fclose(fileIn);
    fclose(fileOut);

    remove(filePath);
    rename(tempFilePath, filePath);

    printf("Line %d deleted successfully.\n", lineNumber);
}

int main() {
    char filePath[] = "example.txt";
    int choice, lineNumber;
    char newText[1024];

    do {
        printf("\n1. Replace a line\n");
        printf("2. Delete a line\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the line number to replace: ");
                scanf("%d", &lineNumber);
                printf("Enter the new text: ");
                scanf(" %[^\n]", newText);
                replaceLine(filePath, lineNumber, newText);
                break;
            case 2:
                printf("Enter the line number to delete: ");
                scanf("%d", &lineNumber);
                deleteLine(filePath, lineNumber);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);
    return 0;
