#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX],rear=-1,front=-1,item,i;

void enqueue()
{
    if(rear==MAX-1)
        is_full();
    else{
        printf("Enter item : ");
        scanf("%d",&item);
        rear++;
        queue[rear] = item;
        printf(" << item enqueue to rear >>\n");
        if(front==-1)
            front++;
    }
}
int dequeue()
{
    if(front==-1){
        is_empty();
    }
    else{
        front++;
        printf(" << item dequeue from front >>\n");
        return front;
    }
}
void is_empty()
{
    if(front==-1)
        printf("-- queue is empty --\n");
    else{
        printf("queue is not empty--\n");
        display();
    }
}
void is_full()
{
    if(rear==MAX-1)
        printf("-- queue is full --\n");
    else{
        printf("queue is not full--\n");
        display();
    }
}
void peek()
{
    if(front==-1)
        is_empty();
    else{
        printf("Front item : %d",queue[front]);
    }
}
void display()
{
    if(front==-1)
        printf("!! no item in queue !!\n");
    else{
        printf("  All data --\n");
        i = front;
        while(i<=rear){
            printf("\t << item : %d >>\n",queue[i]);
            i++;
         }
    }

}
int main()
{
    printf("queue operations --\n");
    int op;
    while(op!=7){
        printf("\t\t\t\t<< options : 1.enqueue | 2.dequeue | 3.display >>\n\t\t\t\t  << 4.is_empty | 5.is_full| 6.peek | 7.exit >>\n");
        printf("\t Enter any options : ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            is_empty();
            break;
        case 5:
            is_full();
            break;
        case 6:
            peek();
            break;
        case 7:
            printf("exiting..");
            exit;
            break;
        default:
            printf("Enter valid option :\n");
        }
    }
}
