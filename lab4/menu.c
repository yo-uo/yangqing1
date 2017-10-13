

/* 
 *  
 * Created by nieJian, 2017/10/11 
 * 
 */  
 
#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#define CMD_MAX_LEN 128
typedef struct DataNode
{
    tLinkNode* next;
    char *cmd;
    char *desc;
    int (*handler)();
}tDataNode;
 
int Initmenu(tLinkTable ** pLinkTable);
tDataNode * FindCmd(tLinkTable * head,char *cmd);
int ShowAllCmd(tLinkTable* head);
int Quit();
int Help();
tLinkTable* head=NULL;

int main()
{
    char cmd[CMD_MAX_LEN];
    Initmenu(&head);
    while(1)
    {
    printf("Please input your command > \n ");
        scanf("%s",cmd);
       tDataNode *q =FindCmd(head,cmd);
       if(q==NULL)
        printf("This is a wrong cmd!\n");
      else
     {
        printf("%s-%s\n",q->cmd,q->desc);
        if(q->handler != NULL)
        q->handler();
    }
    }
    return 0;
}

int Initmenu(tLinkTable ** pLinkTable)
{
    *pLinkTable=CreatLinkTable();
    tDataNode* pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="this is help command";
    pNode->handler=Help;
    AddLinkNode(*pLinkTable,(tLinkNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="version";
    pNode->desc="menu program v2.5";
    pNode->handler=NULL;
    AddLinkNode(*pLinkTable,(tLinkNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="This is quit cmd";
    pNode->handler=Quit;
    AddLinkNode(*pLinkTable,(tLinkNode*)pNode);
    return 0;
}

tDataNode * FindCmd(tLinkTable*head,char * cmd)
{
    tDataNode* p=(tDataNode*)GetHeadNode(head);
    while(p!=NULL)
    {
    if(strcmp(p->cmd,cmd)==0)
        return p;
    p=(tDataNode*)GetNextNode(head,(tLinkNode*)p);
    }
    return NULL;
}

int ShowAllCmd(tLinkTable* head)
{
    tDataNode* p=(tDataNode*)GetHeadNode(head);
    printf("Menu list:\n");
    while(p!=NULL)
    {
    printf("%s-%s\n",p->cmd,p->desc);
    p=(tDataNode*)GetNextNode(head,(tLinkNode*)p);
    }
    return 0;
}

int Quit()
{
    exit(0);
    return 0;
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}
