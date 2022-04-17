#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}NODE;
NODE *head,*new_node,*temp_node,*temp,*temp2;
void create_node()
{
    new_node = (NODE*) malloc(sizeof(NODE));
    new_node->prev = NULL;
    printf("Enter data : ");
    scanf("%d",&new_node->data);
    new_node->next = NULL;
    printf("Node added:\n");

}
void insert_begin()
{
    create_node();
    if(head==NULL)
        head = new_node;
    else{
        temp_node=head;
        temp_node->prev = new_node;
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
        insert_begin();
    else{
        i = 1;
        temp_node = head;
        while(i<=pos-1){
            temp = temp_node;
            temp_node = temp_node->next;
            i++;
        }
        create_node();
        temp->next = new_node;
        new_node->next = temp_node;
        new_node->prev = temp;
        //printf("value : %d\n",temp->data);
        //printf("value : %d\n",temp_node->data);
    }
}
void insert_end()
{
    if(head==NULL)
        insert_begin();
    else{
        temp_node = head;
        while(temp_node->next!=NULL){
            temp_node = temp_node->next;
        }
        create_node();
        temp = temp_node;
        temp_node->next = new_node;
        new_node->prev = temp;
    }
}
void delete_begin()
{
    if(head==NULL)
        printf("No Node here \n");
    else{
        temp_node = head;
        head = temp_node->next;
        head->prev = NULL;
        free(temp_node);
        printf("Begin Node deleted\n");
    }
}
void delete_specific()
{
    int pos=0,i;
    printf("Enter position for delete node : ");
    scanf("%d",&pos);
    if(pos==1)
        delete_begin();
    else if(pos==traversing())
        delete_end();
    else{
        i = 1;
        temp_node = head;
        while(i<=pos){
            temp2 = temp;
            temp = temp_node;
            temp_node = temp_node->next;
            i++;
        }
        temp2->next = temp_node;
        temp_node->prev = temp2;
        free(temp);
        printf("Node deleted\n");
    }
}
void delete_end()
{
    if(head==NULL)
        printf("No node here : \n");
    else{
        temp_node = head;
        while(temp_node->next!=0){
            temp = temp_node;
            temp_node = temp_node->next;
        }
        temp->next = NULL;
        free(temp_node);
        printf("Node deleted from end\n");

    }
}
int traversing()
{
    int count=0;
    temp_node = head;
    while(temp_node!=NULL){
        temp_node = temp_node->next;
        count++;
    }
    printf("Count value : %d\n",count);
    return count;
}
void display()
{
    temp_node = head;
    while(temp_node!=NULL){
        printf("Data : %d\n",temp_node->data);
        temp_node = temp_node->next;
    }
}
int main()
{
    int op;
    while(op!=9){
        printf("Option : 1.insert_begin | \n");
        printf("Enter any option : ");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                insert_begin();
                break;
            case 2:
                insert_specific();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_specific();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                traversing();
                break;
            case 8:
                display();
                break;
            default:
                printf("Enter valid option : \n");
        }
    }
}
