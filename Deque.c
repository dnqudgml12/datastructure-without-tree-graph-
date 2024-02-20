/*

양방향 연결리스트를 통해서
스택과 큐 기능을 동시에 구현한다.
이를 위해서는 덱(Dequeue)를 이용한다.
Dequeue이란? 앞부분에 대한 삽입과 추출 뒤 부분에 대한 삽입과 추출이 모두 가능한 자료구조이다.

tail에 대한 삭제가 매우 용의하다.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;

} Node;

typedef struct _LinkedList
{
    Node *head;
    Node *tail;
    int NumOfData; // 데이터 삽입시에 해당 값 증가 시키기

} List;

void ListInit(List *list);
void AddFirst(List *list, int data);
int DeleteFirst(List *list);
void AddLast(List *list, int data);
int DeleteLast(List *list);
int IsEmpty(List *list);
int Count(List *list);

int main()
{

    List list;
    ListInit(&list);

    AddFirst(&list, 3);
    AddFirst(&list, 2);
    AddFirst(&list, 1);

    AddLast(&list, 4);
    AddLast(&list, 5);
    AddLast(&list, 6);

    printf("Head에서 부터의 삭제 : ");
    while (!IsEmpty(&list))
        printf("%d ", DeleteFirst(&list));
    printf("\n");

    AddFirst(&list, 3);
    AddFirst(&list, 2);
    AddFirst(&list, 1);

    AddLast(&list, 4);
    AddLast(&list, 5);
    AddLast(&list, 6);

    printf("Last에서 부터의 삭제 : ");

    while (!IsEmpty(&list))
        printf("%d ", DeleteLast(&list));

    return 0;
}

void ListInit(List *list)
{
}
void AddFirst(List *list, int data)
{
}
int DeleteFirst(List *list)
{
}
void AddLast(List *list, int data)
{
}
int DeleteLast(List *list)
{
}
int IsEmpty(List *list)
{
}
int Count(List *list)
{
    
}