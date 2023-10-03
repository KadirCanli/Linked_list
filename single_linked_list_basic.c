#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}Node;

void Printlist(Node *ptr)
{
    while(ptr != NULL)
    {
        printf("value is %d \n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    int data1= 20;

    Node *head = NULL;

    head = (Node*)malloc(sizeof(Node));

    head->data = data1;
    head->next = NULL;

    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 30;
    head->next->next = NULL;

    head->next->next = (Node*) malloc(sizeof(Node));
    head->next->next->data = 40;
    head->next->next->next = NULL;

    Printlist(head);

    return 0;
}