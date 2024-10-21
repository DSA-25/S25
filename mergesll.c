#include<stdio.h>
#include<malloc.h>

struct node
{
  int info;
  struct node *next;
};

struct node *create(struct node *head)
{
  int i,n ;
  struct node *temp=NULL, *p=NULL;
  printf("how many nodes :");
  scanf("%d", &n);
  temp = head;
  for (i=0;i<n;i++)
  {
    p=(struct node *)malloc(sizeof(struct node));
    p->next = NULL;
    printf("\nEnter the node data:");
    scanf("%d", &p->info);
    temp->next =p;
     temp=p;
  }

 return (head);
}

void display(struct node *head)
{
  struct node *temp = NULL;
  temp = head->next;

  do
  {
    printf("%d\t", temp->info);
    temp = temp->next;
  } while (temp != NULL);
}

struct node *merge(struct node *head1,struct node *head2,struct node *head3)
{
    struct node *t1=NULL,*t2=NULL,*t3=NULL,*p=NULL;
    t1=head1->next;
    t2=head2->next;
    t3=head3;

    while (t1!=NULL && t2!=NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->next=NULL;
        if (t1->info<t2->info)
        {
            p->info=t1->info;
            t1=t1->next;
        }
        else
        {
            p->info=t2->info;
            t2=t2->next;
        }
        t3->next=p;
        t3=p;
        
    }
    if (t1!=NULL)
    {
        t3->next=t1;
    }
    if (t2!=NULL)
    {
        t3->next=t2;
    }

    return head3;
}

void main()
{
    struct node *create();
    struct node *merge();
    void display();

    struct node *head1=NULL,*head2=NULL,*head3=NULL;
    head1=(struct node *)malloc(sizeof(struct node));
    head1->next=NULL;

    printf("\nCreate 1st list\n");
    head1=create(head1);
    printf("\nThe First list is:\n");
    display(head1);

    head2=(struct node *)malloc(sizeof(struct node));
    head2->next=NULL;

    printf("\nCreate 1st list\n");
    head2=create(head2);
    printf("\nThe First list is:\n");
    display(head2);

    head3=(struct node *)malloc(sizeof(struct node));
    head3->next=NULL;
    head3=merge(head1,head2,head3);

    printf("\nThe merged kistnis:\n");
    display(head3);
}