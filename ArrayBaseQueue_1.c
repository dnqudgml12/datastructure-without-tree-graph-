/*
결과 예시 (Q_SIZE 값이 5일때)

Input some data in Queue!
.......
What is first element of Queue? => 1

What is second element of Queue? => 2

What is number of elements? => 3

What is last element of Queue? => 4

Queue is empty...!

*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define Q_SIZE 5

typedef struct _arrayQueue
{
    int arr[Q_SIZE];
    int front;
    int rare;

} Queue;

void QueueInit(Queue *q);
void Enqueue(Queue *q, int data);
void Dequeue(Queue *q);
int IsEmpty(Queue *q);
int IsFull(Queue *q);
int QueueSize(Queue *q);
int QueuePeek(Queue *q);

int main(void)
{

    Queue *q = (Queue *)malloc(sizeof(Queue));

    QueueInit(q);

    printf("Input some data in Queue!\n");
    printf(".......\n");

    for (int i = 0; i < Q_SIZE - 1; i++)
    {
        Enqueue(q, i + 1);
    }

    printf("What is first element of Queue? => ");
    printf("%d\n\n", QueuePeek(q));

    Dequeue(q);

    printf("What is second element of Queue? => ");
    printf("%d\n\n", QueuePeek(q));
    printf("What is number of elements? => ");
    printf("%d\n\n", QueueSize(q));
    Dequeue(q);
    Dequeue(q);
    printf("What is last element of Queue? => ");
    printf("%d\n\n", QueuePeek(q));
    Dequeue(q);

    if (IsEmpty(q))
        printf("Queue is empty...!\n");
    else
        printf("Queue is not empty...!\n");

    return 0;
}

void QueueInit(Queue *q)
{
}

int IsEmpty(Queue *q)
{
}

int IsFull(Queue *q)
{
}

void Enqueue(Queue *q, int data)
{
}

void Dequeue(Queue *q)
{
}

int QueueSize(Queue *q)
{
}

int QueuePeek(Queue *q)
{
}