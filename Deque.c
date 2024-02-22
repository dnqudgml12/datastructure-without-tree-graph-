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
    list->head=NULL;
    list->tail=NULL;
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
void AddFirst(List *list, int data)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=list->head;
       if(IsEmpty(list)){
      list->head=newNode;
      list->tail=newNode;
    }else{
        list->head->left=newNode;
        //newNode->right=list->head하지 않는 이유
        //newNode->left는 NULL가리키도록 설정했음 위에서
        //근데 newNode다음에 오는 list->head->left는 가르키는 값을 설정하도록 두지않음
        // linked list특성상 list->head->right는 옆을 가르키도록 되있으므로 여기서 는 
        // 작성된 코드 처럼 사용되야함
        list->head=newNode;

    }


    list->NumOfData++;

}
int DeleteFirst(List *list)
{
       if(IsEmpty(list)){
        return -1;
    }
    Node *delNode;
    delNode=list->head;
    int retdata=0;
    retdata=delNode->data;
    list->head=list->head->right;
  
    if(list->head){
        list->head->left=NULL;//헤드가 있으면 새로운 값 들어오기전 젤 왼쪽이 비어있음
    }else{
        list->tail=NULL; // 리스트가 비어있는것
    }
      free(delNode);
        list->NumOfData--;
    delNode=NULL;
    return retdata;

}
void AddLast(List *list, int data)
{

    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->right=NULL;
    newNode->left=list->tail;
        if(IsEmpty(list)){
      list->head=newNode;
      list->tail=newNode;
    }else{
        list->tail->right=newNode;
        //여기서 list->tail->left는 가르키고 있는 것이 그전 리스트이고
        //list->tail->right를 새로운 노드를 가르키도록 해야함
        // 안해놓으면 비어있으므로
        list->tail=newNode;

    }


    


}
int DeleteLast(List *list)
{
       if(IsEmpty(list)){
        return -1;
    }
    Node *delNode;
    delNode=list->tail;
    int retdata=0;
    retdata=delNode->data;
    list->tail=list->tail->left;
    

    //없어도 되지만 조건 확실히하기 위해 필요
    if(list->tail){
        list->tail->right=NULL;//헤드가 있으면 새로운 값 들어오기전 젤 왼쪽이 비어있음
    }else{
        list->head=NULL; // 리스트가 비어있는것
    }
    
    free(delNode);
    
    list->NumOfData--;
     delNode=NULL;
    return retdata;




}

int Count(List *list)
{

    return list->NumOfData;
    
}