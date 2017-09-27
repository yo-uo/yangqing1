//
// Created by yangqing on 2017/9/25
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

int help();
int add();
int sub();
int multi();
int divide();
int time();
int power();
int quit();

/* menu program */
static tDataNode head[] =
{
    {"version","menu program v2.0",NULL,&head[1]},
    {"help","this is help cmd!",help,&head[2]},
    {"add","this is add cmd!",add,&head[3]},
    {"sub","this is sub cmd!",sub,&head[4]},
    {"mul","this is sub cmd!",multi,&head[5]},
    {"div","this is divide cmd!",divide,&head[6]},
    {"pow","this is power cmd!",power,&head[7]},
    {"time","this is time cmd!",time,&head[8]},
    {"quit","this is quit cmd!",quit,NULL}
};

int main()
{
    char cmd[CMD_MAX_LEN];
    printf("welcome use 'help' to get how to use this system !\n");
    while(1)
    {
        printf("input a cmd >");
        scanf("%s",cmd);
        tDataNode  *p = FindCmd(head,cmd);
        if(p == NULL)
        {
            printf("wrong cmd!");
            continue;
        }
        printf("%s ---- %s \n",p->cmd,p->desc);
        if(p->handler !=NULL)
        {
            p->handler();
        }
    }
}

int help()
{
    ShowAllCmd(head);

}

int add()
{
    int a,b;
    printf("please input two numbers >\n");
    scanf("%d %d",&a,&b);
    int c=a+b;
    printf("the result is:\n");
    printf("%d+%d=%d\n",a,b,c);
    return 0;
}

int sub()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c=a-b;
    printf("the result is:\n");
    printf("%d-%d=%d\n",a,b,c);
    return 0;
}

int multi()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c=a*b;
    printf("the result is:\n");
    printf("%d*%d=%d\n",a,b,c);
    return 0;
}

int divide()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c=a/b;
    printf("the result is:\n");
    printf("%d/%d=%d\n",a,b,c);
    return 0;
}

int power()
{
    double a,b;
    printf("please input two double numbers:\n");
    scanf("%lf %lf,&a,&b");
    double c=pow(a,b);
    printf("the result is:\n");
    printf("%.6f^%.6f=%.6f\n",a,b,c);
    return 0;
}

int time()
{
    time_t t=time(0);
    char temp[64];
    strftime(temp,sizeof(temp),"%Y/%m/%d %X %A",localtime(&t));
    puts(temp);
    return 0;
}

int quit()
{
    exit(0);
}
