#ifndef __LINKEDNODEQUEUE_H__
#define __LINKEDNODEQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#ifndef datatype
#define datatype int
#endif


typedef struct node {
    datatype data;
    struct node *next;
}LinkedNode;


LinkedNode *LinkedNodeQueueInit();

// Insert
int LinkedNodeQueueInsertData(LinkedNode *head, const datatype data);
// Pop
datatype LinkedNodeQueuePopDataViaReturnValue(LinkedNode *head);
int LinkedNodeQueuePopDataViaParameter(LinkedNode *head, datatype *data);

//int LinkedNodeQueueGetNumberViaCounting(LinkedNode *head);
#endif