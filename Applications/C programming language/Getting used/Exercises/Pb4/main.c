#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char str[50];
    char oras[50];
    int numar;
    int zipCode;
} Address;

int main()
{
    Address adresa;
    FILE *fp;
    fp = fopen("file.bin", "w+b");
    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    int n = 0;
    printf("Introduce number of addresses: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Introduce the street: ");
        scanf("%s", adresa.str);
        printf("Introduce the town: ");
        scanf("%s", adresa.oras);
        printf("Introduce the number: ");
        scanf("%d", &adresa.numar);
        printf("Introduce the zip code: ");
        scanf("%d", &adresa.zipCode);
        fwrite(&adresa, sizeof(Address), 1, fp);

    }
    fseek(fp, 0, SEEK_END);

    for (int i = n - 1; i >= 0; i--)
    {
        fseek(fp, i * sizeof(Address), SEEK_SET);

        fread(&adresa, sizeof(Address), 1, fp);
        printf("Street: %s\n", adresa.str);
        printf("Town: %s\n", adresa.oras);
        printf("Number: %d\n", adresa.numar);
        printf("Zip Code: %d\n", adresa.zipCode);
    }

    fclose(fp);
    return 0;
}
