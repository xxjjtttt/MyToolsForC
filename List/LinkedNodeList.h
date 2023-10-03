#ifndef __LINKEDNODELIST_H__
#define __LINKEDNODELIST_H__

#include <stdlib.h>
#include <stdio.h>


// 不建议使用除int的其他类型 因为head节点的data域储存着整个链表的节点个数
// 如需使用请忽略头节点储存节点数量的作用
#ifndef datatype
#define datatype int
#endif


typedef struct node {
	datatype data;
	struct node *next;
}LinkedNode;

// 工具箱中链表为头节点储存链表长度
// |4|->|0|->|0|->|0|->|0|
// 以上是Init(4)的返回链表形式


LinkedNode *LinkedNodeListInit(int size);

// GetNumber
int LinkedNodeListGetNumberViaCounting(LinkedNode *head);

// GetFirst // First 为首元节点
LinkedNode *LinkedNodeListGetFirst(LinkedNode *head);

// datatype不为int时需要手动修改输出逻辑
void LinkedNodeListPrint(LinkedNode *head);

// Insert
void LinkedNodeListInsertData(LinkedNode *head, const datatype *data);

// Pop
datatype LinkedNodeListPopDataViaReturnValue(LinkedNode *head, int index);
int LinkNodeListPopDataViaParameter(LinkedNode *head, int index, datatype *data);

// GetData
datatype LinkedNodeListGetDataViaReturnValue(LinkedNode *head, int index);
int LinkedNodeListGetDataViaParameter(LinkedNode *head, int index, datatype *data);

// Attention:datatype不为int时需要屏蔽该函数
//datatype LinkedNodeListGetNumberViaHeadData(LinkedNode *head);

#endif