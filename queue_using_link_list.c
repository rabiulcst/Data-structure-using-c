#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *rear=-1,*front=-1,*new_node,*temp_node,*temp,*pre_front;
int rear_value = 0,i;
void create_node()
{
	new_node = (NODE*) malloc(sizeof(NODE));
	printf("\t Enter data : ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	printf("\t\t\t<< Node inserted >> \n");
	rear_value++;
    if(new_node->next==NULL)
        front = new_node;
}
void enqueue()
{
    int pn=0,nn=0,total=0,ch;
    printf("\t    << Previous item = %d >>\n",rear_value);
    printf("How many item want to enqueue into queue with add previous number of items : ",pn+nn);
    scanf("%d",&pn);
    total=pn;
    while(total>=0){
        if(total == 0){
            printf("Are you want to increase of queue item : For yes enter 1 For no enter 'any int key(without 1)'\n");
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
        else if(rear==-1){
            create_node();
            rear = new_node;
        }
        else{
            create_node();
            temp_node = rear;
            new_node->next = temp_node;
            rear = new_node;
        }
        total--;
    }
}
void dequeue()
{
    if(rear==-1)
        printf("\t << queue underflow >>\n");
    else{
        temp_node = rear;
        while(temp_node->next!=NULL){
            pre_front = temp_node;
            temp_node = temp_node->next;
        }
        pre_front->next = NULL;
        front = pre_front;
        free(temp_node);
        rear_value--;
        printf("front : %d",front->data);
        printf("\t << item dequeue from queue >> \n");
    }
}
void display()
{
	if(rear==-1)
		printf("\t << !No data here : >>\n");
	else{
        i = rear_value-1;
		temp_node = rear;
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
    if(rear==-1)
        printf("\t\t<< queue is empty >>\n");
    else
        printf("\t\t<< queue is not empty >>\n");
}
int main()
{
	int op;
	printf("-- queue operations using link list -----------\n");
	while(1){
		printf("\t\t\t\t\t<<  options >> \n\t\t\t1.enqueue | 2.dequeue | 3.display | 4.rear_value 5.is_empty | 6.exit | \n");
		printf("Enter any option : ");
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
                printf("\t << Rear_value : %d >> \n",rear_value);
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
		printf("----------------------------------------------------------------------------------------------\n");
	}
	return 0;
}

