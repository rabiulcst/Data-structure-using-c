#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int top=-1,stack[MAX],i,j;
void push()
{
	if(top==MAX-1)
		printf("stack overflow\n");
	else{
		int data;
		printf("enter data : ");
		scanf("%d",&data);
		top++;
		stack[top] = data;
		printf("Pushed item into stack \n");
	}
}
void pop()
{
	if(top==-1)
		printf("stack underflow");
	else{
		top--;
		printf("Popped item from stack \n");
	}
}
void display()
{
	printf("print data : \n");
	for(i=top; i>=0; i--	)
		printf("stack[%d] = %d\n",i,stack[i]);
}
void data_in_stack()
{
    i=0;
    int ch=0;
    if(top==-1)
        printf("stack is empty :");
    else{
        int item;
        printf("Enter item for search : ");
        scanf("%d",&item);
        while(i<=top){
            if(item==stack[i])
                ch = 1;
            i++;
        }
    }

    if(ch==1)
        printf("item exit in stack:\n");
    else
        printf("item not exit in stack\n");
}
int main()
{
	int op;

	while(op!=5){
		printf("\noptions : 1.push | 2.pop | 3.display | 5.exit \n");
		printf("Enter any option : ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
            case 4:
                data_in_stack();
                break;
			case 5:
				exit;
				break;
			default:
				printf("Enter valid option :\n");
		}
	}
}
