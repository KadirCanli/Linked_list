#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;


void printList(Node* ptr);
void addNode(int value,Node **);

int main()
{
    Node *head= NULL;
    addNode(10,&head);
    addNode(20,&head);
    addNode(30,&head);
    addNode(40,&head);
    addNode(50,&head);
    addNode(60,&head);
    addNode(70,&head);

    printList(head);

    return 0;
}

void addNode(int value,Node ** head)
{
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
        tempNode = *head;

        while(tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
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