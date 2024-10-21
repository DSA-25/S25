#include<stdio.h>

void main()
{       
    int n,num,i,flag,last;

     printf("\nenter the size of array\n");
     scanf("%d",&n);
     printf("Enter the number you want to search\n");
     scanf("%d",&num); 
     int arr[n];
     printf("Enter The Elements Of arrya\n");
        for ( i = 0; i < n; i++)
         {
            scanf("%d",&arr[i]);
         }
    i=0;
    last=arr[n-1];
    arr[n-1]=num;

    for ( i = 0; i < n; i++)
    {
        if (arr[i]==num)
        {
            goto step6;
        }
        
    }
    step6:arr[n-1]=last;

    if (arr[i]==num)
    {
        printf("Required number is found at location %d",i+1);
    }
    else
       printf("required data not found");

}