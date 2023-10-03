#ifndef __SEQUENCEQUEUE_H__
#define __SEQUENCEQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

// maxsize和datatype根据需求改变
#ifndef maxsize
#define maxsize 5
#endif

#ifndef datatype
#define datatype int
#endif

typedef struct seqqueue {
    datatype queue[maxsize];
    int head_index;
    int tail_index;
    int num;
}SequenceQueue;

SequenceQueue *SequenceQueueInit();

// Insert
int SequenceQueueInsertData(SequenceQueue *seqqueue, const datatype data);
// Pop
int SequenceQueuePopDataViaParameter(SequenceQueue *seqqueue, datatype *data);
datatype SequenceQueuePopDataViaReturnValue(SequenceQueue *seqqueue);

//int SequenceQueueGetStaus(SequenceQueue *seqqueue);
#endif