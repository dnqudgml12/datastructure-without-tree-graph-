/*
�ش� ��ũ�帮��Ʈ�� �⺻���� ��ɰ� ���Ҿ�, ������������ �����͸� �����ϴ� ��ɰ� Ư�� ��带 �����ϴ� ����� �߰��Ѵ�.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
    int data;
    struct _node *next;

} Node;

typedef struct _LinkedList
{
    Node *head;
    Node *tail;
    Node *curr;
    Node *prev;
    int NumOfData; // ������ ���Խÿ� �ش� �� ���� ��Ű��

} List;

void ListInit(List *list);
void ListInsert(List *list, int data);
void ListInsertAscending(List *list, int data); // �����߰��� �Լ�1 : �����͸� ������������ �����Ѵ�.
void LinearSearch(List *list);                  // Search->LinearSearch�� �Լ��� ����
int IsEmpty(List *list);
int Count(List *list);
int Delete(List *list, int data); // ���� �߰��� �Լ�3: Ư����带 �����Ѵ�.
void DeleteAll(List *list);

int main()
{

    List list;
    ListInit(&list);
    IsEmpty(&list);

    printf("�������� ������ ���� ...\n\n");
    ListInsertAscending(&list, 10);
    ListInsertAscending(&list, 2);
    ListInsertAscending(&list, 8);
    ListInsertAscending(&list, 3);
    ListInsertAscending(&list, 20);
    ListInsertAscending(&list, 14);

    printf("Elements : ");
    LinearSearch(&list);
    printf("\n\n");

    printf("Choosing data is deleted!\n\n");
    printf("%d is deleted!\n", Delete(&list, 3));
    printf("\nData list after deleting : ");
    LinearSearch(&list);

    return 0;
}

void ListInit(List *list)
{
    list->tail=NULL;
    list->head=NULL;
    list->curr=NULL;
    list->prev=NULL;
    list->NumOfData=0;
}
int IsEmpty(List *list)
{
    if(list->head==NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

void ListInsert(List *list, int data)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(IsEmpty(list)){
        list->head=newNode;
        list->tail=newNode;
    }
    list->tail->next=newNode;
    list->tail=newNode;
    list->NumOfData++;
}

void ListInsertAscending(List *list, int data)
{

    
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;

    if (IsEmpty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }else{
        list->prev=NULL;
        list->curr=list->head;
        while (list->curr!=NULL&&list->curr->data<data)
        {
            list->prev=list->curr;
            list->curr=list->curr->next;
        
        }

        if(list->prev==NULL){
            newNode->next=list->head;
            list->head=newNode;
        }else{
            list->prev->next=newNode;
            newNode->next=list->curr;
            if(list->curr==NULL){
                list->tail=newNode;
            }
        }
        
    }
    list->NumOfData++;


}



int Count(List *list)
{
    return list->NumOfData;
}

void LinearSearch(List *list)
{

    list->curr=list->head;
    while (list->curr!=NULL)
    {
        printf("%d",list->curr->data);
        list->curr=list->curr->next;
    }
    
}

int Delete(List *list, int data)
{
    Node * delNode;
    if(IsEmpty(list)){
        return -1;
    }else{
        list->prev=NULL;
        list->curr=list->head;
        while (list->curr!=NULL&&list->curr->data!=data)
        {
            list->prev=list->curr;
            list->curr=list->curr->next;
        }

        delNode=list->curr;
        if(list->prev==NULL)

        {
            delNode=list->head;
            list->head=list->head->next;
            

        }else{
            list->prev->next=list->curr->next;
            if(list->curr==NULL){
                delNode=list->tail;
                list->tail=list->prev;
            }

        }
    }
    free(delNode);
    list->NumOfData--;
return data;

}

void DeleteAll(List *list)
{
    Node *delNode;
    while (!IsEmpty(list))
    {
        
    delNode=list->head;
    list->head=list->head->next;
    free(delNode);
    }

    list->tail=NULL;
    list->prev=NULL;
    list->curr=NULL;
    
    list->NumOfData=0;
    

    
}