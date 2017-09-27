//
// Created by yangqing on 2017/9/25
//

#ifndef LAB3_LINKLIST_H
#define LAB3_LINKLIST_H

/* data struct and its operation */
typedef struct DataNode
{
    char  *cmd;
    char * desc;
    int (*handler)();
    struct DataNode *next;
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tDataNode *head,char *cmd);

/* show all cmd in linklist */
int ShowAllCmd(tDataNode *head);
