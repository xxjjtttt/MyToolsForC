#include "SequenceStack.h"


SequenceStack *SequenceStackInit() {
    SequenceStack *seqstack = (SequenceStack *)malloc(sizeof(SequenceStack));
    seqstack->tail_index = -1;
    return seqstack;
}

/* 查询栈状态
 * Parameter SequenceStack 结构体地址
 * retval -1 栈满 0 栈空 1 可操作栈
 */
int SequenceStackGetStaus(SequenceStack *seqstack) {
    if (seqstack->tail_index + 1 == maxsize) {
        return -1;
    }else if (seqstack->tail_index == -1) {
        return 0;
    }
    return 1;
}

/* 数据入栈
 * Parameter SequenceStack 结构体地址 待插入数据
 * retval 1 成功 -1 失败
 */
int SequenceStackInsertData(SequenceStack *seqstack, const datatype data) {
    if (SequenceStackGetStaus(seqstack) != -1) {
        seqstack->tail_index++;
        seqstack->stack[seqstack->tail_index] = data;
        return 1;
    }
    return -1;
}

/* 数据出栈
 * Parameter SequenceStack 结构体地址
 * retval 所删除数据
 */
datatype SequenceStackPopDataViaReturnValue(SequenceStack *seqstack) {
    datatype retval;
    if(SequenceStackGetStaus(seqstack) != 0) {
        retval = seqstack->stack[seqstack->tail_index];
        seqstack->tail_index--;
    }
    return retval;
}

/* 数据入栈
 * Parameter SequenceStack 结构体地址 被删除数据
 * retval 1 成功 -1 失败
 */
int SequenceStackPopDataViaParameter(SequenceStack *seqstack, datatype *data) {
    if(SequenceStackGetStaus(seqstack) != 0) {
        *data = seqstack->stack[seqstack->tail_index];
        seqstack->tail_index--;
        return 1;
    }
    return -1;
}