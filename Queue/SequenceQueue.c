#include "SequenceQueue.h"


SequenceQueue *SequenceQueueInit() {
    SequenceQueue *seqqueue = (SequenceQueue*)malloc(sizeof(SequenceQueue));
    seqqueue->head_index = 0;
    seqqueue->tail_index = -1;
    seqqueue->num = 0;
    return seqqueue;
}
// TODO: 需要添加一个队列元素 用来记录队列中元素个数 不用再去想算法了

/*
 * 查询队列状态
 * prameter SequenceQueue 结构体地址
 * retval 状态码 0 空队列 -1 满队列 1 可操作队列
 */
int SequenceQueueGetStaus(SequenceQueue *seqqueue) {
    if (seqqueue->num == 0) {
        return 0;
    } else if (seqqueue->num == maxsize) {
        return -1;
    }
    return 1;
}

/* 队列插入数据
 * prameter SequenceQueue 结构体地址 datatype 所要插入的数据
 * retval 状态码 1 成功插入 -1 失败插入
 */
int SequenceQueueInsertData(SequenceQueue *seqqueue, const datatype data) {
    if (SequenceQueueGetStaus(seqqueue) != -1) {
        seqqueue->tail_index++;
        seqqueue->tail_index %= maxsize;
        seqqueue->num++;
        seqqueue->queue[seqqueue->tail_index] = data;
        return 1;
    }
    return -1;
}

/* 队列删除数据 并通过参数返回被删除元素
 * prameter SequenceQueue 结构体地址 datatype 储存被删除元素
 * retval 状态码 1 成功删除 -1 失败删除
 */
int SequenceQueuePopDataViaParameter(SequenceQueue *seqqueue, datatype *data) {
    if (SequenceQueueGetStaus(seqqueue) != 0) {
        *data = seqqueue->queue[seqqueue->head_index];
        seqqueue->head_index++;
        seqqueue->head_index %= maxsize;
        seqqueue->num--;
        return 1;
    }
    return -1;
}

/* 队列删除数据 并通过返回值返回被删除元素
 * prameter SequenceQueue 结构体地址
 * retval 被删除元素
 */
datatype SequenceQueuePopDataViaReturnValue(SequenceQueue *seqqueue) {
    datatype retval;
    if (SequenceQueueGetStaus(seqqueue) != 0) {
        retval = seqqueue->queue[seqqueue->head_index];
        seqqueue->head_index++;
        seqqueue->head_index %= maxsize;
        seqqueue->num--;
    }
    return retval;
}