#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;


void printList(Node* ptr);
void insertNode(int value,Node **);

int main()
{
    Node *head= NULL;
    insertNode(40,&head);
    insertNode(20,&head);
    insertNode(10,&head);
    insertNode(30,&head);
    insertNode(70,&head);
    insertNode(35,&head);
    insertNode(50,&head);
    insertNode(25,&head);
    insertNode(60,&head);
    insertNode(15,&head);

    printList(head);

    return 0;
}

void insertNode(int value,Node ** head)
{
    Node *prevNode;
    Node *newNode;
    Node *tempNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;

    newNode->data =value;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else{
        if(value<(*head)->data)
        {
            newNode->next = *head;
            *head = newNode;
        }
        else{
            prevNode = *head;
            tempNode = prevNode;
        

        while(tempNode != NULL && value>=tempNode->data)
        {
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
        newNode->next = tempNode;
        prevNode->next = newNode;
    }
    }
}

void printList(Node *ptr)
{
    while(ptr !=0)
    {
        printf("The value is : %d \n", ptr->data);
        ptr = ptr->next;
    }
}