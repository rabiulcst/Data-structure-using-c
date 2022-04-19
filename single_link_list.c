#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *head,*new_node,*temp_node,*temp,*temp2;

void create_node()
{
	new_node = (NODE*) malloc(sizeof(NODE));
	printf("\t Enter data : ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	printf("\t\t\t<< Node inserted >> \n");
}
void insert_start()
{
	create_node();
	if(head==NULL)
		head = new_node;
	else{

		temp_node = head;
		new_node->next = temp_node;
		head = new_node;
	}
}
void insert_specific()
{
    int pos,i;
    printf("Enter position : ");
    scanf("%d",&pos);

    if(pos==1)
        insert_start();
    else{
        i = 1;
        temp_node = head;
        while(i<pos){
            temp = temp_node;
            temp_node = temp_node->next;
            i++;
        }
        create_node();
        temp->next = new_node;
        new_node->next = temp_node;
    }
}
void insert_end()
{
	if(head==NULL)
		printf("no previous node here\n");
	else{
		temp_node = head;
		while(temp_node->next!=NULL){
			temp_node = temp_node->next;
		}
		create_node();
        temp_node->next = new_node;
	}
}
void delete_start()
{
    if(head==NULL)
        printf("No node here :\n");
    else{
        temp_node = head;
        head = temp_node->next;
        free(temp_node);
        printf("        << Node deleted from start >>\n");
    }
}
void delete_specific()
{
    int pos=0,i;
    if(head==NULL)
        printf("No node here : ");
    else{
        printf("Enter position for delete node : ");
        scanf("%d",&pos);
        if(pos==1)
            delete_start();
        else{
            i = 1;
            temp_node = head;
            while(i<=pos){
                temp = temp2;
                temp2 = temp_node;
                temp_node = temp_node->next;
                i++;
            }
            temp->next = temp_node;
            free(temp2);
            printf("\t\t<< Node deleted from specific position >>\n");
        }
    }
}
void delete_end()
{
    if(head==NULL)
        printf("No node available for delete : \n");
    else{
        temp_node = head;
        while(temp_node->next!=NULL){
            temp = temp_node;
            temp_node = temp_node->next;
        }
        temp->next = NULL;
        free(temp_node);
        printf("\t\t<< Node deleted from end >>\n");
    }
}
void display()
{
    int n=1;
	temp_node = head;
	if(head==NULL)
		printf(" !! No data here :");
	else{
        printf("<< Displaying all node data >>\n");
        printf("\t-------------------\n");
		while(temp_node!=NULL){
			printf("\t|%d.Node data : %d |\n",n,temp_node->data);
			temp_node = temp_node->next;
			n++;
		}
		printf("\t-------------------\n");
	}
}

void reverse_list()
{
    temp = head;
    temp_node = head->next;
    temp->next=NULL;

    while(temp_node->next!=NULL){
            temp2 = temp_node;
            temp_node = temp_node->next;
            temp2->next = temp;
            temp = temp2;
    }
    temp_node->next = temp;
    head = temp_node;
    printf("Reverse completed : Enter 8 for show :\n");
}
void travers()
{
    int count_node=0;
    if(head==NULL)
        printf("Number of node : %d",count_node);
    else{
        temp_node = head;
        while(temp_node!=NULL){
            temp_node = temp_node->next;
            count_node++;
        }
        printf("\t\t << Number of node = %d >>\n",count_node);
    }

}
int main()
{
	int op;
	printf("--Single Link List operations -----------\n");
	while(op!=10){
		printf("\t\t\t\t\t\<<  options >> \n\t\t\t1.insert_start | 2.insert_specific | 3.insert_end | \n\t\t\t4.delete_start | 5.delete_specific | 6.delete_end |\n\t\t\t7.Count_node   | 8.show_node_data  | 9.ReverseList|\n\t\t\t\t\t<<  10.Exit >>\n");
		printf("Enter any option : ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				insert_start();
				break;
            case 2:
                insert_specific();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                delete_start();
                break;
            case 5:
                delete_specific();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                travers();
                break;
			case 8:
				display();
				break;
            case 9:
                reverse_list();
                break;
            case 10:
                printf("\t\texiting...\n");
                printf("\t\tExited");
                exit;
                break;
            default:
                printf("Please enter valid option : \n");
		}
	}

	return 0;
}
