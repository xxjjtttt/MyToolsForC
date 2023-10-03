#include "SequenceList.h"

SequenceList *SequenceListInit () {
	SequenceList *seqlist = (SequenceList *)malloc(sizeof(SequenceList));
    seqlist->size = 0;
	return seqlist;
}

int SequenceListGetLength(SequenceList *seqlist) {
	return seqlist->size;
}

void SequenceListInsertOneDataToTail(SequenceList *seqlist, datatype data) {
    if (seqlist->size < maxsize) {
        seqlist->list[seqlist->size] = data;
        seqlist->size++;
    }
}

void SequenceListInsertOneDataToHead(SequenceList *seqlist,datatype data) {
    if (seqlist->size < maxsize) {
        for (int n = seqlist->size; n > 0; n--) {
            seqlist->list[n] = seqlist->list[n-1];
        }
        seqlist->list[0] = data;
        seqlist->size++;
    }
}

void SequenceListPopFromHeadByParameter(SequenceList *seqlist, datatype *data) {
    if (seqlist->size > 0) {
        *data = seqlist->list[0];
        for (int n = 0; n < seqlist->size; n++) {
            seqlist->list[n] = seqlist->list[n+1];
        }
        seqlist->size--;
    }
}

void SequenceListPopFromTailByParameter(SequenceList *seqlist, datatype *data) {
    if (seqlist->size > 0) {
        *data = seqlist->list[seqlist->size-1];
        seqlist->size--;
    }
}

void SequenceListInsertOneDataByIndex(SequenceList *seqlist,int index,datatype data) {
    if (seqlist->size < maxsize && index >=0 && index <= seqlist->size) {
        seqlist->list[index] = data;
        seqlist->size++;
    }
}

void SequenceListPopOneDataByIndexByParameter(SequenceList *seqlist, int index, datatype *data) {
    if (seqlist->size > index && index >= 0) {
        *data = seqlist->list[index];
        for (int n = index; n < seqlist->size; n++) {
            seqlist->list[n] = seqlist->list[n+1];
        }
        seqlist->size--;
    }
}

void SequenceListGetDataByParameter(SequenceList *seqlist, int index, datatype *data) {
    if (index >= 0 && seqlist->size > index) {
        *data = seqlist->list[index];
    }
}

datatype SequenceListGetDataByReturnValue(SequenceList *seqlist, int index) {
    datatype retval;
    if (index >= 0 && seqlist->size > index) {
        retval = seqlist->list[index];
    }
    return retval;
}