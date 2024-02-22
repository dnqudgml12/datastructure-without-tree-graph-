/*
�ش� ��ũ�帮��Ʈ�� �⺻���� �������� ����,Ž��,ī����, ��ü���� �ϴ� ��ɸ��� �ο��Ѵ�.
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
    int NumOfData;

} List;

void ListInit(List *list);
void ListInsert(List *list, int data); // tail�� �����͸� �߰��ϴ� ���
void LinearSearch(List *list);
int IsEmpty(List *list);
int Count(List *list);
void DeleteAll(List *list); // ������ ������(���)�� ��� ����, ������ head���� ����

int main()
{

    List list;
    ListInit(&list);
    IsEmpty(&list);

    printf("������ ���� ...\n\n");
    ListInsert(&list, 10);
    ListInsert(&list, 42);
    ListInsert(&list, 54);
    ListInsert(&list, 66);
    ListInsert(&list, 89);

    printf("������ ��� : ");
    LinearSearch(&list);
    printf("\n\n");

    printf("������ ���� ����\n");
    DeleteAll(&list);
    IsEmpty(&list);
    return 0;
}

void ListInit(List *list)
{
    list->head=0;
    list->tail=0;
    list->curr=0;
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
    Node *newData= (Node *) malloc(sizeof(Node));
    newData->data=data;
    newData->next=NULL;

    if(IsEmpty(list)){
        list->head=newData;
        list->tail=newData;
    }
    list->tail->next=newData;
    list->tail=newData;

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
    list->curr=NULL;
    list->NumOfData=0;
    
}