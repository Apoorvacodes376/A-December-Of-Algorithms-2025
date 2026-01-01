#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;

};

// void input()
// {
//     struct node *temp=NULL;
//     printf("entr the number of elements:");
//     int n;
//     scanf("%d",&n);
//     printf("enter the elements:");
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&)
//     }
// }

void create(struct Node *l,int n)
{ 
        int e;
        printf("\nEnter %d elements:",n); 
        struct Node *tmp=NULL;
        
        for(int i=0;i<n;i++)
        { 
            scanf("%d",&e); 
            tmp=malloc(sizeof(struct Node));
            tmp->data=e; 
            tmp->next=NULL; 
            l->next=tmp; l=tmp; 
        }
        printf("Linked List Created successfully\n");
}

void print(struct Node *l)
{ 
    struct Node *tmp=l->next; 
    printf("\nThe elements are:"); 
    while(tmp!=NULL)
    { 
        printf("%d ",tmp->data); 
        tmp=tmp->next;
    } 
    printf("\n");
}

// void swap(struct Node *l)
// {
//     struct Node *temp=l->next;
//     int count=0;
//     while(temp!=NULL)
//     {
//         count++;
//     }
//     for(int i=count;i>0;i--)
//     {
//         if(i%2==0)
//         {
//             temp->next[i]=temp->next[count];
//         }
//     }
//     while (temp!=NULL)
//     {
//         printf("%d ",temp->data);
//     }
    
// }

void swap(struct Node *l) 
{ 
    struct Node *temp = l->next; 
    while (temp != NULL && temp->next != NULL) 
    {
        int t = temp->data; 
        temp->data = temp->next->data; 
        temp->next->data = t; 
        temp = temp->next->next; 
    } 
}


int main()
{
    struct Node *head=NULL;
    int e,n,p,ch;
    head=malloc(sizeof(struct Node)); 
    printf("Enter the number of elements in the list:"); 
    scanf("%d",&n);
    head->next=NULL; 
    create(head,n); 
    swap(head);
    print(head);
    return 0;
}