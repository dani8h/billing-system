
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"


int main()
{   int n, tax;
    FILE *fp;
    char name[50], number[13];
    fp = fopen("customer details.csv","r+");

    welcome();
    
    printf("please select the option :  \n 1.existing cutomer 2.new customer\n ");
    scanf("%d",&n);

    if(n==1){
        printf("Enter phone number : ");
        scanf("%s",&number);
        display(fp, atoi(number));
    }

    else if(n==2){
        printf("please enter name\n");
        scanf("%s", name);
        printf("please enter number\n");
        scanf("%s",&number);
        
        read(fp,name,atoi(number));
    }
    printf("enter the number of items\n");
    scanf("%d",&n);
    struct items list[n];
    read_price(list,n);
    printf("enter the tax percentage\n");
    scanf("%d",&tax);
    float total = calculate(list,n,tax); 
    output(list,n,total);


}