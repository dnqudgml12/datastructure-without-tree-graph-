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
    int NumOfData;

} List;

void QueueInit(List *list);
void Enqueue(List *list, int data);
int Dequeue(List *list);
int IsEmpty(List *list);
int Count(List *list);

int main()
{
    List list;
    QueueInit(&list);
    printf("Insert...\n");
    Enqueue(&list, 1);
    Enqueue(&list, 10);
    Enqueue(&list, 15);
    Enqueue(&list, 18);
    Enqueue(&list, 22);
    Enqueue(&list, 30);

    printf("....\n");
    printf("Elements : ");

    while (!IsEmpty(&list))
    {

        printf("%d ", Dequeue(&list));
    }

    return 0;
}
void QueueInit(List *list)
{
}
void Enqueue(List *list, int data)
{
}
int Dequeue(List *list)
{
}
int IsEmpty(List *list)
{
}
int Count(List *list)
{
}