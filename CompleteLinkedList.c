#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct linkedlist
{
    int v;
    struct linkedlist *link;
}node;
node *start;
//for creating a new linked list
void createLinkedList()
{
    if(start!=NULL)
    {
        printf("You have already created a linked list.If you want to insert item then press 2\n");
    }
    else{
    int d;
    node *temp;
    temp=(node *)malloc(sizeof(node));
    printf("Enter your first value...\n");
    scanf("%d",&d);
    temp->v=d;
    temp->link=NULL;
    start=temp;
    }
}
//This code for print the whole list....
void printList()
{
    if(start==NULL)
    {
        printf("list is empty or not created yet....\n");
    }
    else
    {
        node *temp;
        temp=start;
        while(temp!=NULL)
        {
            printf("%d->",temp->v);
            temp=temp->link;
        }
        printf("NULL\n");
    }
}
//this code for inserting
//At begining of linked list
void insertAtBegin()
{
    if(start==NULL)
    {
        printf("First create a linked list and then try to insert...\n");
    }
    else{
    int d;
    node *temp;
    temp=(node *)malloc(sizeof(node));
    printf("Enter your value...\n");
    scanf("%d",&d);
    temp->v=d;
    temp->link=start;
    start=temp;
    }
}
//this code for insert at the end
void insertAtEnd()
{
     if(start==NULL)
    {
        printf("First create a linked list and then try to insert...\n");
    }
    else
    {
        int d;
        node *temp,*temp1;
        temp=(node *)malloc(sizeof(node));
        printf("Enter your value...\n");
        scanf("%d",&d);
        temp->v=d;
        temp->link=NULL;
        temp1=start;
        while(temp1->link!=NULL)
        {
            temp1=temp1->link;
        }
        temp1->link=temp;
    }
}
//this code search an item in linked list
void searchitem()
{
    if(start==NULL)
    {
        printf("First create a linked list and then try to insert...\n");
    }
    else
    {
        int value,flag=0;
        node *temp1;
        printf("Enter your value  u want search...\n");
        scanf("%d",&value);
        temp1=start;
        while(temp1!=NULL)
        {
            if(temp1->v==value)
            {
                flag=1;
                break;
            }
            temp1=temp1->link;
        }
        if(flag==1)
            printf("Element are exist in list\n");
        else
            printf("Element not found\n");
    }
}
//this code for insert after a given value
void insertAfterValue()
{
    if(start==NULL)
    {
        printf("First create a linked list and then try to insert...\n");
    }
    else
    {
        int d,value;
        node *temp,*temp1;
        temp=(node *)malloc(sizeof(node));
        printf("Enter your value after u want add...\n");
        scanf("%d",&value);
        printf("ENter data which u want to add\n");
        scanf("%d",&d);

        temp->v=d;
        temp->link=NULL;
        temp1=start;
        while(temp1!=NULL)
        {
            if(temp1->v==value)
                break;
            temp1=temp1->link;
        }
        temp->link=temp1->link;
        temp1->link=temp;
    }

}
//this code for inserting a element at given positionn
void insertAtPosition()
{
    if(start==NULL)
    {
        printf("First create a linked list and then try to insert...\n");
    }
    else
    {
        int d,posi,c=1;
        node *temp,*temp1;
        temp=(node *)malloc(sizeof(node));
        printf("Enter your position where u want add...\n");
        scanf("%d",&posi);
        printf("ENter data which u want to add\n");
        scanf("%d",&d);

        temp->v=d;
        temp->link=NULL;
        temp1=start;
        while(temp1!=NULL)
        {
            c++;
            if(c==posi)
                break;
            temp1=temp1->link;
        }
        temp->link=temp1->link;
        temp1->link=temp;
    }
}
//this code for inserting a value in linked list....
void insertInList()
{
    int ch;
    printf("Where You want to insert..press\n");
    printf(" 1. if you want to insert at begning \n 2. if you want to insert at end\n 3.if you want to insert after given value\n 4. if you want to insert at any position\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insertAtBegin();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAfterValue();
            break;
        case 4:
            insertAtPosition();
    }}
//this code for deleting a node from begining....
void deleteAtBegin()
{
    node *temp;
    temp=start;
    start=temp->link;
    free(temp);
    printf("Item from begin has deleted...\n");
}
//this code for delete item from end.....
void deleteAtEnd()
{
    node *temp,*temp1;
    temp1=start;
    while(temp1->link!=NULL)
    {
        temp=temp1;
        temp1=temp1->link;
    }
    temp->link=NULL;
    free(temp1);
}
//this code for delete a perticular value
void deleteValue()
{
    int dv;
    node *temp,*temp1;
    temp1=start;
    printf("Enter the value which u want to delete...\n");
    scanf("%d",&dv);
    while(temp1->link!=NULL)
    {
        if(temp1->v==dv)
            break;
        temp=temp1;
        temp1=temp1->link;
    }
    temp->link=temp1->link;
    free(temp1);
}
//this code for delete at given position
void deleteAtPosition()
{
    int posi,c=1;
    node *temp,*temp1;
    temp1=start;
    printf("Enter the position where u want to delete...\n");
    scanf("%d",&posi);
    while(temp1->link!=NULL)
    {
        if(c==posi)
            break;
        temp=temp1;
        c++;
        temp1=temp1->link;
    }
    temp->link=temp1->link;
    free(temp1);

}
//this code for deleting a node
void deleteItem()
{
    int ch;
    printf("Where You want to delete..press\n");
    printf(" 1. if you want to delete at begning \n 2. if you want to delete at end\n 3.if you want to delete given value\n 4. if you want to delete at any position\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            deleteAtBegin();
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            deleteValue();
            break;
        case 4:
            deleteAtPosition();
    }
}
//find out the length of given linked list....
void findLength()
{
    if(start==NULL)
        printf("List is not created yet....\n");
    else
    {
        node *temp;
        int c=0;
        temp=start;
        while(temp!=NULL)
        {
            c++;
            temp=temp->link;
        }
        printf("Lenght of list is :  %d \n",c);
    }
}
//to sort a linked list
void sortList()
{
    int temp2;
    node *temp,*temp1;
    temp=start;
    while(temp->link!=NULL)
    {
        temp1=temp->link;
        while(temp1!=NULL)
        {
            if(temp->v>temp1->v)
            {
                temp2=temp->v;
                temp->v=temp1->v;
                temp1->v=temp2;
            }
            temp1=temp1->link;
        }
        temp=temp->link;
    }
}
//to reversing a linked list
void reverseList()
{
    node *temp,*temp1,*temp2;
    temp=start;
    temp1=temp->link;
    temp->link=NULL;
    while(temp1!=NULL)
    {
        temp2=temp1->link;
        temp1->link=temp;
        temp=temp1;
        temp1=temp2;
    }
    start=temp;
}
void main()
{
    int flag=1,choice;
    printf("Welcome to linked list programme\n");
    printf("These are few operation which provided by us..... Press\n");
    while(flag)
    {
        printf("1. If you Want to create a linked list.\n");
        printf("2. If you want to insert in existing list.\n");
        printf("3. If you want to see complete list.\n");
        printf("4. If you want to delete an item.\n");
        printf("5. If u want to find out the length.\n");
        printf("6. If u want to search any item.\n");
        printf("7. Reverse the linked list.\n");
        printf("8. Sort the linked list.\n");
        printf("9. If you want to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Wowww you want to create a new linked list....sounds great\n");
            createLinkedList();
            break;
        case 2:
            insertInList();
            break;
        case 3:
            printList();
            break;
        case 4:
            deleteItem();
            break;
        case 5:
            findLength();
            break;
        case 6:
            searchitem();
            break;
        case 7:
            reverseList();
            break;
        case 8:
            sortList();
            break;
        case 9:
            printf("Okk bye enjoy your life");
            flag=0;
        }
    }
}
