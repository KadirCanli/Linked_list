#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void printandcount(Node* head)
{
    Node* tmp = head;
    int cnt =0;
    while(tmp!=NULL)
    {
        printf("val : %d \n",tmp->data);
        tmp = tmp->next;
        cnt++;
        printf("cnt val : %d \n",cnt);
    }
}

Node* searchptr(Node* head,int val)
{
    Node *tmp =head;
    while(head!=NULL)
    {
        if(val==head->data)
        {
            tmp = head;
            return tmp;
        }
        else
        {
            tmp = head->next;
        }
    }
    return NULL;
}
Node* insertAtBegin(Node* head,int val)
{
    Node* new_node =(Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = head;
    head = new_node;
    return head;
}
Node* insertAtEnd(Node* head,int val)
{
    Node* ptr;
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    ptr = head;
    while(ptr->next !=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return head;    
}
Node* insertNodeAfter(Node* head,int val,int whichdata)
{
    Node* ptr;
    Node* afterptr;
    Node* temp;
    Node* new_node =(Node*)malloc(sizeof(Node));
    new_node->data = val;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data == whichdata)
        {
            afterptr = temp;
            ptr = temp->next;
        }
        temp= temp->next;
    }
    afterptr->next =new_node;
    new_node->next = ptr;
    return head;
}
Node* insertNodeBefore(Node* head, int val,int whichdata)
{
    Node* ptr;
    Node* beforeptr;
    Node* temp;
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    temp=head;
    while(temp!=NULL)
    {
        beforeptr = temp;
        if(temp->next->data == whichdata)
        {
            ptr = temp->next;
            break;
        }
        temp = temp->next;
    }
    beforeptr->next = new_node;
    new_node->next = ptr;
    return head;
}
Node* deleteFirstNode(Node* head)
{
    Node* temp;
    temp = head;
    
    head= head->next;
    free(temp);
    return head;
}
Node* deleteLastNode(Node* head)
{
    Node* preptr;
    Node* temp;
    temp =head;
    while(temp->next!=NULL)
    {

        preptr = temp;
        temp = temp->next;        
    }
    preptr->next = NULL;
    free(temp);
    return head;
    
}
Node* deleteNode(Node* head,int val)
{
    Node* preptr;
    Node* temp;
    temp = head;
    if(temp->data== val)
    {
        head = deleteFirstNode(head);
        return head;
    }
    else
    {
        while(temp->data!=val)
        {
            preptr = temp;
            temp = temp->next;
        }
        preptr->next =temp->next;
        free(temp);
        return head;
    }    
}


int main()
{
    Node* start = NULL;
    start = insertAtBegin(start,10);
    start = insertAtEnd(start,20);
    start = insertAtEnd(start,30);
    start = insertAtEnd(start,40);
    start = insertNodeAfter(start,50,10);
    start = insertNodeBefore(start,60,20);
    start = deleteFirstNode(start);
    start = deleteLastNode(start);
    start = deleteNode(start,30);
    printandcount(start);
    
    return 0;
}