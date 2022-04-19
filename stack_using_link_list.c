#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *top=-1,*new_node,*temp_node,*temp,*temp2;
int top_value = 0,i;
void create_node()
{
	new_node = (NODE*) malloc(sizeof(NODE));
	printf("\t Enter data : ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	printf("\t\t\t<< Node inserted >> \n");
	top_value++;
}
void push()
{
    int pn=0,nn=0,total=0,ch;
    printf("\t    << Previous item = %d >>\n",top_value);
    printf("How many item want to push into stack with add previous number of items : ",pn+nn);
    scanf("%d",&pn);
    total=pn;
    while(total>=0){
        if(total == 0){
            printf("Are you want to increase of stack item : For yes enter 1 For no enter 'any int key(without 1)'\n");
            scanf("%d",&ch);
            if(ch==1){
                printf("Enter your new number of item value : ");
                scanf("%d",&nn);
                total+=nn+1;
            }
            else{
                break;
            }
        }
        else if(top==-1){
            create_node();
            top = new_node;
        }
        else{
            create_node();
            temp_node = top;
            new_node->next = temp_node;
            top = new_node;
        }
        total--;
    }
}
void pop()
{
    if(top==-1)
        printf("\t << pop underflow >>\n");
    else{
        temp_node = top;
        top = temp_node->next;
        free(temp_node);
        printf("\t<< Popped item from stack >>\n");
        top_value--;
    }
}
void display()
{
	if(top==-1)
		printf("\t << !No data here : >>\n");
	else{
        i = top_value;
		temp_node = top;
		printf("<< Displaying all node data >>\n");
        printf("\t-------------------\n");
        printf("\t             ______\n");
		while(temp_node!=NULL){
            printf("\t            \n");
			printf("\tstack data %d: | %d |\n",i,temp_node->data);
			printf("\t             ______\n");
			temp_node = temp_node->next;
            i--;
		}
	}
}
void is_empty()
{
    if(top==-1)
        printf("\t\t<< Stack is empty >>\n");
    else
        printf("\t\t<< Stack is not empty >>\n");
}
int main()
{
	int op;
	printf("--Single Link List operations -----------\n");
	while(1){
		printf("\t\t\t\t\t\<<  options >> \n\t\t\t1.Push | 2.pop | 3.display | 4.top_value 5.is_empty | 6.exit | \n");
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
                printf("\t << Top value : %d >> ",top_value);
                break;
            case 5:
                is_empty();
                break;
            case 6:
                printf("\t\texiting...\n");
                printf("\t\tExited");
                exit(0);
                break;
            default:
                printf("Please enter valid option : \n");
		}
	}
	return 0;
}

