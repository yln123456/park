#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

#define TRUE 1
#define FALSE 0
#define ERROR 1
#define OK 0
#define OVERFLOW -1

typedef char QElemType;

typedef struct QNode
{
	QElemType data[15];
	struct QNode * next;
}QNode;
typedef QNode* QueuePtr;
typedef struct
{
	QueuePtr front;		//头指针
	QueuePtr rear;		//尾指针
}LinkQueue;				//队列的链式存储表示

/*链栈函数列表*/
int InitQueue(LinkQueue *Q);	//初始化队列

void ClearQueue(LinkQueue *Q);	//置空Q

void DestroyQueue(LinkQueue *Q);	//销毁Q

int QueueEmpty(LinkQueue *Q);	//判断Q是否为空

int QueueLength(LinkQueue *Q);	//返回Q元素的个数

int GetHead(LinkQueue Q,QElemType *e);	//获取队头元素

int EnQueue(LinkQueue *Q,QElemType *e);	//元素e入队

int DeQueue(LinkQueue *Q,QElemType *e);	//元素e出队

void QueueTraverse(LinkQueue *Q);	//访问元素

#endif

