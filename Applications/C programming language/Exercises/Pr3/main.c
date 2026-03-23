#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c;
    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("The file doesn't exist!\n");
        exit(0);
    }
    int i = 0, word = 1;
    while((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
        i++;
        if(c == ' ')
            word++;
    }
    printf("\n\nThere are %d words and %d characters.\n", word, i);
    fclose(fp);
    return 0;
}
