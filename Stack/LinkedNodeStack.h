#ifndef __LINKEDNODESTACK_H__
#define __LINKEDNODESTACK_H__

#include <stdio.h>
#include <stdlib.h>

#ifndef datatype
#define datatype int
#endif

typedef struct node {
    datatype data;
    struct node *next;
}LinkedNode;

LinkedNode *LinkedNodeStackInit();
// Insert
int LinkedNodeStackInsertData(LinkedNode *head, const datatype data);
// Pop
datatype LinkedNodeStackPopDataViaReturnValue(LinkedNode *head);
int LinkedNodeStackPopDataViaParameter(LinkedNode *head, datatype *data);


#endif