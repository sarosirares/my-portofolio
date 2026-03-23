#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int n = 0;
    int op = 0;
    char text[100] = {'\0'};
    while(op != 3)
    {
        printf("Enter 1 for renaming the line\n2 for removing the line\n3 for exit\nOption: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                printf("\nEnter the line that you want to change or to remove: ");
                scanf("%d", &n);
                printf("Enter a text: ");
                scanf("%s", text);
                renameline(n, text);
                break;
            case 2:
                printf("\nEnter the line that you want to change or to remove: ");
                scanf("%d", &n);
                removeline(n);
                break;
        }
    }
    return 0;
}

void renameline(int l, const char *text)
{
    FILE *file, *temp;
    file = fopen("file.txt", "r");
    if(file == NULL)
    {
        printf("Error!");
        exit(0);
    }
    temp = fopen("temp.txt", "w");
    if(temp == NULL)
    {
        printf("Error!");
        exit(0);
    }
    char string[100];
    int currentline = 0;
    while(fgets(string, sizeof(string), file) != NULL)
    {
        currentline++;
        if(currentline == l)
            fprintf(temp, "%s\n", text);
        else
            fprintf(temp, "%s", string);
    }

    fclose(temp);
    fclose(file);

    remove("file.txt");
    rename("temp.txt", "file.txt");
}

void removeline(int l)
{
    FILE *file, *temp;
    file = fopen("file.txt", "r");
    if(file == NULL)
    {
        printf("Error!");
        exit(0);
    }
    temp = fopen("temp.txt", "w");
    if(temp == NULL)
    {
        printf("Error!");
        exit(0);
    }
    char string[100];
    int currentline = 0;

    while(fgets(string, sizeof(string), file) != NULL)
    {
        currentline++;
        if(currentline != l)
            fprintf(temp, "%s", string);
    }

    fclose(temp);
    fclose(file);

    remove("file.txt");
    rename("temp.txt", "file.txt");
}

