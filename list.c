#include<stdio.h>
#include<malloc.h>
// #include"list.h"

void main()
{
    int n;

    void create();
    void display();
    void createlist();
    void display_list();

    printf("\nHow many no of vertices\n");
    scanf("%d",&n);
    int a[n][n];
    printf("\nCreate matrix");
    create(n,a);
    printf("\nThe adjacency matrix is\n");
    display(n,a);
    printf("\nThe adjacency list is\n");
    createlist(n,a);
    display_list(n);
}

struct node
{
    int data;
    struct node *next;
}*v[10];

int n;
struct node *p=NULL,*temp=NULL;

void create(int n,int a[n][n])
{
    int i,j,x;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n ; j++)
        {
            if (i != j)
            {
                printf("Enter the values between %d and %d vertices\n",i,j);
                scanf("%d",&x);
                if (x > 0)
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
                 
            }
            else
            {
                a[i][j]=0;
            }
           
        }
        
    }
    
}

void display(int n,int a[n][n])
{   
    int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void createlist(int n,int a[n][n])
{
    int i,j;
    for ( i = 0; i < n; i++)
    {
        v[i]=NULL;
        for ( j = 1; j <=n; j++)
        {
            if (a[i][j]!=0)
            {
                p=(struct node *)malloc(sizeof(struct node));
                p->data=j;
                p->next=NULL;
                if(v[i]==NULL)
                v[i]=temp=p;
                else
                temp->next=p;
                temp=p;
            }
        }
    }
}

void display_list(int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        temp=v[i];
        printf("\n%d\t",i);
        while (temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        } 
        printf("NULL");  
    } 
}