#ifndef __SEQUENCELIST_H__
#define __SEQUENCELIST_H__

#include <stdlib.h>
#include <stdio.h>

// maxsize和datatype根据需求改变
#ifndef maxsize
#define maxsize 100
#endif

#ifndef datatype
#define datatype int
#endif

typedef struct seqlist {
	datatype list[maxsize];
	int size;
}SequenceList;

SequenceList *SequenceListInit ();


int SequenceListGetLength(SequenceList *seqlist);
// Insert
void SequenceListInsertOneDataToTail(SequenceList *seqlist, datatype data);
void SequenceListInsertOneDataToHead(SequenceList *seqlist, datatype data);
void SequenceListInsertOneDataByIndex(SequenceList *seqlist, int index, datatype data);// index从0开始
// Pop
void SequenceListPopFromHeadByParameter(SequenceList *seqlist, datatype *data);// data保存pop出来的数据
void SequenceListPopFromTailByParameter(SequenceList *seqlist, datatype *data);// data保存pop出来的数据
void SequenceListPopOneDataByIndexByParameter(SequenceList *seqlist, int index, datatype *data);// index从0开始 // data保存pop出来的数据
// Get
void SequenceListGetDataByParameter(SequenceList *seqlist, int index, datatype *data);
datatype SequenceListGetDataByReturnValue(SequenceList *seqlist, int index);

#endif