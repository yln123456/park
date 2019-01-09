#include "LinkQueue.h"
#include <string.h>
/********队列的链式实现******/
/*
retunn:
    OK:表示初始化成功
    OVERFLOW:表示初始化失败，内存未开成功
parm:
    *Queue:表示要开辟的空间的队列地址
*/
int InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
    {
        printf("Q->front malloc error!\n");
        return OVERFLOW;
    }
    Q->front->next = NULL;
    return OK;
}
//销毁队列
void DestroyQueue(LinkQueue *Q)
{
    free(Q->front);
    free(Q->rear);
    Q->front = Q->rear = NULL;
}
//置空队列
void ClearQueue(LinkQueue *Q)
{
    Q->front = Q->rear;
}
//判断Q是否为空
int QueueEmpty(LinkQueue *Q)
{
    if(Q->front == Q->rear)
        return TRUE;
    return FALSE;
}
//返回Q元素个数
int QueueLength(LinkQueue *Q)
{
    QueuePtr temp = Q->front;
    int length = 0;
    while(temp != Q->rear)
    {
        ++length;
        temp = temp->next;
    }
    return length;
}
//获取对头元素
int GetHead(LinkQueue Q, QElemType *e)
{
    QNode *p;
    if(Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    strcpy(e,p->data);
    return OK;
}
//元素e入队
int EnQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr temp = (QueuePtr)malloc(sizeof(QNode));
    if(!temp)
    {
        printf("temp malloc error!\n");
        return ERROR;
    }
    strcpy(temp->data,e);
    temp->next = NULL;
    Q->rear->next = temp;
    Q->rear = temp;
    return OK;
}
//元素e出队
int DeQueue(LinkQueue *Q, QElemType *e)
{
    if(QueueEmpty(Q) == TRUE)
    {
        printf("queue is NULL!\n");
        return ERROR;
    }
    QueuePtr temp = Q->front->next;
    if(Q->front->next == Q->rear)
        Q->rear = Q->front;
    strcpy(temp->data,e);
    Q->front->next = temp->next;
    free(temp);
    temp = NULL;
    return OK;
}
//访问元素
void QueueTraverse(LinkQueue *Q)
{
    if(QueueEmpty(Q) == TRUE)
    {
        printf("  queue is empty!\n");
    }
    QueuePtr temp = Q->front;
    //printf("将队列中的所有元素出队：\n");
    while(temp != Q->rear)
    {
        temp = temp->next;
        printf("  %s\n",temp->data);
    }
    printf("\n");
}

