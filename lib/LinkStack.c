/***************************************
author:荣存庆
mail:xxxxxx
desc:链式栈的基本操作
**************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

/*
*链栈有头节点，头结点的值默认为HEADVALUE
*/

/*
function:
    初始化链式栈
return:
	top:表示初始化成功,并返回初始化的地址
    NULL:表示初始化失败，内存未开成功 直接返回空值
parm:
	无
*/

LinkStackPtr initLinkStack(){
    LinkStackPtr top;
    top=NULL;
    top=(LinkStackPtr)malloc(sizeof(LinkStack));
    strcpy(top->data,"123");
    top->next=NULL;
    if(NULL==top){
        return NULL;
    }else{
        return top;
    }
}

/*
function:
    销毁链式栈
return:
	TRUE:表示销毁成功
    FALSE:表示销毁失败
parm:
	要销毁的链式栈的栈顶首地址的取地址,是一个二级指针
*/

int destroyLinkStack(LinkStackPtr *top){
    LinkStackPtr p;
    p=NULL;
    if(NULL==*top){
        return FALSE;
    }
    while(NULL!=*top){
        p=(*top)->next;
        free(*top);
        *top=p;
    }
    free(*top);
    free(p);
    return TRUE;
}

/*
function:
    清空链式栈
return:
	TRUE:表示清空成功
    FALSE:表示清空失败
parm:
	要清空的链式栈的栈顶首地址的取地址
*/

int clearLinkStack(LinkStackPtr *top){
    LinkStackPtr p;
    p=NULL;
    if(NULL==*top){
        return FALSE;
    }
    while(NULL!=(*top)->next){
        p=(*top)->next;
        free(*top);
        *top=p;
    }
    return TRUE;
}

/*
function:
    判断链栈是否为空
return:
	TRUE:链栈为空
    FALSE:链栈不为空
parm:
	要清空的链式栈的栈顶首地址
*/

int isEmptyLinkStack(LinkStackPtr top){
    return NULL==top->next?TRUE:FALSE;
}

/*
function:
    求链栈的长度
return:
	count:链栈的长度
parm:
	链式栈的栈顶首地址
*/

int lengthLinkStack(LinkStackPtr top){
    int count=0;
    LinkStackPtr p;
    p=top;
    while(NULL!=p->next){
        p=p->next;
        count++;
    }
    return count;
}

/*
function:
    用 e 返回 stack的栈顶元素。
return:
    TRUE:获取成功
    FALSE:获取失败
parm:
	链式栈的栈顶首地址， 元素e的地址
*/

int getTopLinkStack(LinkStackPtr top, elemType *e){
    if(NULL==top->next || NULL==top){
        return FALSE;
    }
    strcpy(e,top->data);
    return TRUE;
}

/*
function:
    将元素e压入链栈
return:
    TRUE:获取成功
    FALSE:获取失败
parm:
	链式栈的栈顶首地址的取地址， 元素e
*/

int pushLinkStack(LinkStackPtr *top, elemType *e){
    if(NULL==*top){
        return FALSE;
    }
    LinkStackPtr p;
    p=NULL;
    p=(LinkStackPtr)malloc(sizeof(LinkStack));
    if(NULL==p){
        return FALSE;
    }
    strcpy(p->data,e);
    p->next=*top;
    *top=p;
    return TRUE;
}

/*
function:
    展示链栈
return:
    无
parm:
	链式栈的栈顶首地址
*/

void displayLinkStack(LinkStackPtr top){
    LinkStackPtr p;
    if(NULL==top->next){
        printf("  park is empty\n");
        return;
    }
    p=top;
    printf("  ");
    puts(p->data);
    p=p->next;
    while(p->next!=NULL){
        printf("  ");
        puts(p->data);
        p=p->next;
    }
    printf("\n");
}

/*
function:
    元素出栈，并用e带回出栈元素
return:
    TRUE:出栈成功
    FALSE:出栈失败
parm:
	链式栈的栈顶首地址的取地址， 元素e的地址
*/

int popLinkStack(LinkStackPtr *top, elemType *e){
    if(NULL==*top){
        return FALSE;
    }
    LinkStackPtr p;
    strcpy(e,(*top)->data);
    p=(*top)->next;
    *top=p;
    return TRUE;
}

