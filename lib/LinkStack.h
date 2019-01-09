#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
//定义宏常量

#define TRUE 1
#define FALSE 0
#define HEADVALUE -1

//设置一个数据类型
typedef char elemType;

//栈链表节点结构体
typedef struct node{
	struct node *next;//指针域
    elemType data[15];//数据域
}LinkStack, *LinkStackPtr;



LinkStackPtr initLinkStack();

int destroyLinkStack(LinkStackPtr *top);

int clearLinkStack(LinkStackPtr *top);

int isEmptyLinkStack(LinkStackPtr top);

int lengthLinkStack(LinkStackPtr top);

int getTopLinkStack(LinkStackPtr top, elemType *e);

int pushLinkStack(LinkStackPtr *top, elemType *e);

void displayLinkStack(LinkStackPtr top);

int popLinkStack(LinkStackPtr *top, elemType *e);

#endif
