#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

int read_price(struct items *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter item name : ");
        scanf("%s", &a[i].item_name);
        printf("Enter the price of the item : ");
        scanf("%f", &a[i].price);
        printf("quantity : ");
        scanf("%d", &a[i].quantity);
    }
    return n;
}

float calculate(struct items *a, int n, float tax)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + (float)a[i].quantity * a[i].price;
    }

    total = total + total * tax / 100;
    return total;
}

void output(struct items *a, int n, float total)
{
    printf("***************************************************\n");
    printf("*************THANK YOU FOR SHOPPING****************\n");
    printf("item name\t price\t quantity\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t   %f\t   %d\n", a[i].item_name, a[i].price, a[i].quantity);
    }
    printf("the total price is %f\n", total);
}


void welcome(){
    printf("\n\n\n                  ****\n                 *** *\n                ***  *\n               ***   * \n              ***    *\n             ***     *\n            ***      *\n\n");
    printf("\n ***************************************** \n \t   WELCOME \n  ***************************************** \n");
    
    
}

void display(FILE *fp, int n)
{
    char c[100];
    int count = 0;
    while (fgets(c, 100, fp) != NULL)
    {
        char *name = strtok(c, ",");
        int number = atoi(strtok(NULL, ","));
        
        if (number == n)
        {
            printf("%s\n", name);
            printf("%d\n", number);
            count = 1;
            break;
        }
    }
    if(count == 0){
        printf("number not found\n");
        }
}

void read(FILE *fp, char* name, int number){
    fseek(fp,0,SEEK_END);
    fprintf(fp,"%s,%d\n",name,number);

}