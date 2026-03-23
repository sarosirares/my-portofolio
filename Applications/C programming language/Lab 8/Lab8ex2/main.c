#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int account_num;
    char name[50];
    float current_balance;
} Record;

int main()
{
    FILE *file_ptr, *file1_ptr, *file2_ptr;
    Record rec;
    file_ptr = fopen("file.txt", "r");
    if(file_ptr == NULL)
        printf("Esti babalau");
    file1_ptr = fopen("file1.txt", "r");
    if(file_ptr == NULL)
        printf("Esti babalau");
    file2_ptr = fopen("file2.txt", "w");

    fscanf(file_ptr, "%d%s%f", &rec.account_num, rec.name, &rec.current_balance);
    printf("%d\n%s\n%f", rec.account_num, rec.name, rec.current_balance);

    return 0;
}
