#ifndef PARKING_H
#define PARKING_H

extern LinkStackPtr parkstack;
extern LinkStackPtr assstack;
extern LinkQueue que;
extern int c;

//初始化程序
void init();

//判断停车场是否有车
int isparking();

//展示主界面
void showview();

//操作指令
void operation();

//停车操作
void paking();

//提示停车场内的车量
void displayview();

//提示在外排队的车辆
void displayviewque();

//停车场出车操作
void pickup();
#endif
