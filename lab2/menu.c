#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display();
void add();
void sub();
void cmbine();
void help();
void hello();
void min();
 
int main()
{
    char cmd[20];
    while (1)
    {
        scanf("%s",cmd);
        if (strcmp(cmd,"display") == 0)
        {
            display();
        }
        else if (strcmp(cmd,"add") == 0)
        {
            add();
        }
        else if (strcmp(cmd,"sub") == 0)
        {
            sub();
        }
        else if (strcmp(cmd,"cmbine") == 0)
        {
            cmbine();
        }
        else if (strcmp(cmd,"help") == 0)
        {
            help();
        }
        else if (strcmp(cmd,"min") == 0)
        {
            min();
        }
        else if (strcmp(cmd,"quit") == 0)
        {
            exit(0);
        }
        else if (strcmp(cmd,"hello") == 0)
        {
            hello();
        }

    }
}

void hello()
{
    printf("hello world!\n");
}

void help()
{
    printf("This is a help document!");
}

void add()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    a=a+b;
    printf("The Result is : %d",a);
}

void sub()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    a=a-b;
    printf("The Result is: %d",a);
}

void cmbine()
{
    char *s;
    char a[10],b[10];
    printf("please input two strings:\n");
    scanf("%s %s",a,b);
    s=strcat(a,b);
    printf("the result is:\n");
    printf("%s",s);
}

void min()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    if(b<a)
     a=b;
    printf("the smaller number is: %d",a);
}

void display()
{
    printf("This is the menu!");
}
