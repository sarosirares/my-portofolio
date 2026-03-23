#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 21

int main()
{
    char word[SIZE];
    char *smallest, *largest;

    smallest = (char *)calloc(SIZE, sizeof(char));
    largest = (char *)calloc(SIZE, sizeof(char));

    printf("Enter a word (max 20 characters): ");
    scanf("%s", word);

    strcpy(smallest, word);
    strcpy(largest, word);

    while(strlen(word) != 4)
    {
        if(strcmp(word, smallest) < 0)
            strcpy(smallest, word);
        if(strcmp(word, largest) > 0)
            strcpy(largest, word);
        printf("Enter a new word (max 20 characters): ");
        scanf("%s", word);
    }

    printf("The smallest word inserted is: %s\n", smallest);
    printf("The largest word inserted is: %s\n", largest);

    free(smallest);
    free(largest);

    return 0;
}


