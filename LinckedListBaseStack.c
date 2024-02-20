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
    int NumOfData;

} List;

void StackInit(List *list);
void Push(List *list, int data);
int Pop(List *list);
int IsEmpty(List *list);

int main()
{
    List list;

    StackInit(&list);

    printf("스택에 대한 데이터 삽입...\n\n");
    Push(&list, 3);
    Push(&list, 4);
    Push(&list, 6);
    Push(&list, 10);
    Push(&list, 12);
    Push(&list, 20);

    printf("스택에 대한 데이터 출력 : ");
    while (!IsEmpty(&list))
    {

        printf("%d ", Pop(&list));
    }
    return 0;
}

void StackInit(List *list)
{
}
void Push(List *list, int data)
{
}
int Pop(List *list)
{
}
int IsEmpty(List *list)
{
}
