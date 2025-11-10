#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push()
{
     int x;
    printf("enter data");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("overflow \n");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{

        int item;
        if(top==-1)
        {
            printf("underflow \n");
        }
        else
        {
            item=stack[top];
            top--;
            printf("%d",item);
        }
}
void peek()
{
        int item;
        if(top==-1)
        {
            printf("underflow \n");
        }
        else
        {
            printf("%d",stack[top]);
        }

}
int main()
{
    int choice;
    while (1)
    {
         printf("Choose the operation you want to want to operate \n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.Exit\n");
    printf("enter no");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
    }
    }
    return 0;
}

