#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/LinkStack.h"
#include "./lib/LinkQueue.h"
#include "./lib/parking.h"



int main()
{
    init();
    while(1){
        system("clear");
        showview();
        displayview();
        displayLinkStack(parkstack);
        displayviewque();
        QueueTraverse(&que);
        printf("  请输入操作:\n");
        operation();
        printf("  按下任意键继续\n");
        getchar();
    }
    return 0;
}
