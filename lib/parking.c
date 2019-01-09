#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
#include "LinkQueue.h"
#include "parking.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

LinkStackPtr parkstack;
LinkStackPtr assstack;
LinkQueue que;
int cd=0;
int isparking(LinkStackPtr top,char *str){
    LinkStackPtr p;
    if(NULL==top->next){
        printf("  park is empty\n");
        return 0;
    }
    p=top;
    while(p->next!=NULL){
        if(strcmp(str,p->data)==0){
            return 1;
        }
        p=p->next;
    }
    return 0;
}
void showview(){
     printf("\n");
     printf(ANSI_COLOR_RED"             停车场管理系统\n"ANSI_COLOR_RED);
     printf(ANSI_COLOR_BLUE"  ******************************************\n"ANSI_COLOR_BLUE);
     printf("  *                                        *\n");
     printf("  *                                        *\n");
     printf("  *请输入操作:                              *\n");
     printf("  *                                        *\n");
     printf("  *1:停车  2：退车  3：退出                 *\n");
     printf("  *                                        *\n");
     printf("  *                                        *\n");
     printf("  ******************************************\n");

}

void operation(){
    char c;
    printf("  ");
    scanf("%c", &c);
    switch(c){
        case '1': paking();break;
        case '2': pickup();break;
        case '3': exit(1);break;
        default:printf(" 输入错误，请重新输入\n");return;
    }
}

void paking(){
    char str[50];
    printf(ANSI_COLOR_RESET"  请输入停车的车牌号：\n"ANSI_COLOR_RESET);
    scanf("%s", str);
    getchar();
    if(cd==lengthLinkStack(parkstack)){
        printf("  停车场已满，该车进入队列等候\n");
        EnQueue(&que,str);
    }else{
        pushLinkStack(&parkstack,str);
    }
}


void init(){

    printf("  请输入停车场最大可停数量\n");
    printf("  ");
    scanf("%d", &cd);
    getchar();
    parkstack=initLinkStack();
    assstack=initLinkStack();
    InitQueue(&que);
}
void displayview(){
    printf("  停车场内的车牌号如下：\n");
}

void pickup(){
    char str[50];
    char e[50], e2[50];
    printf(ANSI_COLOR_MAGENTA"  请输入你想退车的车牌号,,或者输入q退出:\n"ANSI_COLOR_MAGENTA);
    printf("  ");
    while(scanf("%s",str)!=EOF){
        getchar();
        if(isparking(parkstack,str)){
            break;
        }else if(strcmp(str,"q")==0){
                return;
        }else{
            printf("  您输入的车不在停车场内, 请重新输入车牌号,或者输入q退出\n");
        }
    }
    getTopLinkStack(parkstack,e);
    if(strcmp(str,e)==0){
        popLinkStack(&parkstack,e2);
        printf("  车牌号位 %s 的车以出停车场\n",e2);
        if(!QueueEmpty(&que)){
            GetHead(que,e2);
            pushLinkStack(&parkstack,e2);
            DeQueue(&que,e2);
            printf("  排队的 %s 车进入停车场\n",e2);
        }
    }else{
        while(strcmp(str,e)!=0){
            popLinkStack(&parkstack,e);
            pushLinkStack(&assstack,e);
            printf("  %s 车进入辅助车道\n", e);
            getTopLinkStack(parkstack,e);
        }
        popLinkStack(&parkstack,e);
        printf("  %s 车已出停车场\n", e);
        while(!isEmptyLinkStack(assstack)){
            popLinkStack(&assstack,e);
            pushLinkStack(&parkstack,e);
            printf("  %s 车已回停车场\n", e);
        }
        if(!QueueEmpty(&que)){
            GetHead(que,e2);
            pushLinkStack(&parkstack,e2);
            DeQueue(&que,e2);
            printf("  排队的 %s 车进入停车场\n",e2);
        }
    }
}

void displayviewque(){
    printf("  在停车场外排队的车如下:\n");
}
