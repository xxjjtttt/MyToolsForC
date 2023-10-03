#ifndef __SEQUENCESTACK_H__
#define __SEQUENCESTACK_H__

#include <stdio.h>
#include <stdlib.h>

#ifndef maxsize
#define maxsize 5
#endif

#ifndef datatype
#define datatype int
#endif

typedef struct stack {
    datatype stack[maxsize];
    int tail_index;
}SequenceStack;


SequenceStack *SequenceStackInit();
// Insert
int SequenceStackInsertData(SequenceStack *seqstack, const datatype data);

// Pop
datatype SequenceStackPopDataViaReturnValue(SequenceStack *seqstack);
int SequenceStackPopDataViaParameter(SequenceStack *seqstack, datatype *data);

#endif