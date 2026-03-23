#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int word = 0, letter = 0;
    char string[100];
    char ch;
    const char filename[50] = "file.txt";

    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error!");
        exit(0);
    }
    while(fgets(string, sizeof(string), fp))
    {
        printf("%s\n\n", string);
        word++;
    }
    fseek(fp, 0, SEEK_SET);
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == ' ')
            word++;
        letter++;
    }

    fclose(fp);

    printf("The number of words: %d\nThe number of letters: %d\n", word, letter);

    return 0;
}
