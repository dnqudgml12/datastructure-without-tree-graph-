/*
해당 링크드리스트는 기본적인 기능과 더불어, 오름차순으로 데이터를 삽입하는 기능과 특정 노드를 삭제하는 기능을 추가한다.
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
    int NumOfData; // 데이터 삽입시에 해당 값 증가 시키기

} List;

void ListInit(List *list);
void ListInsert(List *list, int data);
void ListInsertAscending(List *list, int data); // 새로추가된 함수1 : 데이터를 오름차순으로 삽입한다.
void LinearSearch(List *list);                  // Search->LinearSearch로 함수명 변경
int IsEmpty(List *list);
int Count(List *list);
int Delete(List *list, int data); // 새로 추가된 함수3: 특정노드를 삭제한다.
void DeleteAll(List *list);

int main()
{

    List list;
    ListInit(&list);
    IsEmpty(&list);

    printf("오름차순 데이터 삽입 ...\n\n");
    ListInsertAscending(&list, 10);
    ListInsertAscending(&list, 2);
    ListInsertAscending(&list, 8);
    ListInsertAscending(&list, 3);
    ListInsertAscending(&list, 20);
    ListInsertAscending(&list, 14);

    printf("데이터 목록 : ");
    LinearSearch(&list);
    printf("\n\n");

    printf("선택한 데이터 삭제 실행\n\n");
    printf("%d이(가) 삭제되었습니다!\n", Delete(&list, 3));
    printf("\n삭제후 데이터 목록 : ");
    LinearSearch(&list);

    return 0;
}

void ListInit(List *list)
{
}

void ListInsert(List *list, int data)
{
}

void ListInsertAscending(List *list, int data)
{
}

int IsEmpty(List *list)
{
}

int Count(List *list)
{
}

void LinearSearch(List *list)
{
}

int Delete(List *list, int data)
{
}

void DeleteAll(List *list)
{

    
}