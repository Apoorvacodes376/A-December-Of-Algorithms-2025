#include<stdio.h>
#include<stdlib.h>

struct node
{
    int n;
    int *a;
    int t;
};

void getdata(struct node *l)
{
    printf("enter n:");
    scanf("%d",&l->n);
    printf("enter array:");
    for(int i=0;i<l->n;i++)
    {
        scanf("%d",&l->a[i]);
    }
    printf("enter the target to be found:");
    scanf("%d",&l->t);
}

void find(struct node *l)
{
    int sum=0;
    int i=0;
    while((i!=l->n)&&(sum<=l->t))
    {
        sum+=l->a[i];
        if(sum==l->t)
        {
            printf("target found!");
            break;
        }
        i++;
    }
    // while((i!=l->n)&&(sum<=l->t))
    // {
    //     sum+=l->a[i];
    //     printf("%d ",l->a[i]);
    //     if(sum==l->t)
    //     {
    //         printf("target found!");
    //         break;
    //     }
    //     i++;
    // }
}

int main()
{
    struct node *l=NULL;
    l=malloc(sizeof(struct node));
    getdata(l);
    find(l);
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int n;
    int *a;
    int t;
};

void getdata(struct node *l)
{
    //struct node *l=NULL;
    //l=malloc(sizeof(struct node));
    printf("enter n:");
    scanf("%d",&l->n);
    l->a = malloc(l->n * sizeof(int));
    printf("enter array:");
    for(int i=0;i<l->n;i++)
    {
        scanf("%d",&l->a[i]);
    }
    printf("enter the target to be found:");
    scanf("%d",&l->t);
}

void find(struct node *l)
{
    int sum=0;
    int i=0;
    
    for(int j=0;j<l->n;j++)
    {
        sum=0;
        for(int k=0;k<l->n-1;k++)
        {
            sum+=l->a[k];
            printf("%d ",l->a[k]);
            if(sum==l->t)
            {
                printf("target found again!");
                break;
            }
        }
        
        if(sum==l->t)
        break;
    }
}

int main()
{
    struct node *l=NULL;
    l=malloc(sizeof(struct node));
    getdata(l);
    find(l);
    return 0;
}