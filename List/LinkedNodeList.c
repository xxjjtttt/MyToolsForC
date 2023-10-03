#include "LinkedNodeList.h"

LinkedNode *LinkedNodeListGetFirst(LinkedNode *head) {
    return head->next;
}

//datatype LinkedNodeListGetNumberViaHeadData(LinkedNode *head) {
//    head->data = LinkedNodeListGetNumberViaCounting(head);
//    return head->data;
//}

int LinkedNodeListGetNumberViaCounting(LinkedNode *head) {
    LinkedNode *p = LinkedNodeListGetFirst(head);
    int num = 0;
    for (; p != NULL; p = p->next) {
        num++;
    }
    return num;
}

LinkedNode *LinkedNodeListInit(int size) {
	LinkedNode *head, *t, *p;
    head = (LinkedNode*)malloc(sizeof(LinkedNode));
	p = head;
	for (int n = 0; n < size; n++) {
		t = (LinkedNode*)malloc(sizeof(LinkedNode));
		t->next = NULL;
		p->next = t;
		p = t;
	}
	return head;
}


void LinkedNodeListPrint(LinkedNode *head) {
    LinkedNode *t = LinkedNodeListGetFirst(head);
    while (t != NULL) {
        printf("%d ",t->data); // 这里更改输出逻辑
        t = t->next;
    }
}


void LinkedNodeListInsertData(LinkedNode *head, const datatype *data) {
    LinkedNode *t = LinkedNodeListGetFirst(head);
    int index = 0;
    while (t != NULL) {
        if (&(data[index]) != NULL) {
            t->data = data[index];
            index++;
            t = t->next;
        }
    }
}

datatype LinkedNodeListGetDataViaReturnValue(LinkedNode *head, int index) {
    int num = LinkedNodeListGetNumberViaCounting(head);
    LinkedNode *p = LinkedNodeListGetFirst(head);
    datatype retval;
    if (index >= 0 && index <= num) {
        for (int n = 0; n < index; n++) {
            p = p->next;
        }
        retval = p->data;
        return retval;
    }
    return retval;
}

/* 通过参数获取链表数据
 * parameter LinkedNode 头节点地址 索引 储存返回值介质的地址
 * retval 1 成功 -1 失败
 */
int LinkedNodeListGetDataViaParameter(LinkedNode *head, int index, datatype *data) {
    int num = LinkedNodeListGetNumberViaCounting(head);
    LinkedNode *p = LinkedNodeListGetFirst(head);
    if (index >= 0 && index <= num) {
        for (int n = 0; n < index; n++) {
            p = p->next;
        }
        *data = p->data;
        return 1;
    }
    return -1;
}

/* 通过参数删除链表数据
 * parameter LinkedNode 头节点地址 索引
 * retval 目标节点数据
 */
datatype LinkedNodeListPopDataViaReturnValue(LinkedNode *head, int index) {
    int num = LinkedNodeListGetNumberViaCounting(head);
    LinkedNode *p = head, *t;
    datatype retval;
    if (index >= 0 && index <= num) {
        for (int n = 0; n < index; n++) {
            p = p->next; // 此时p指向待删除节点的前一个地址
        }
        t = p->next;
        retval = t->data;
        p->next = t->next;
        free(t);
    }
    return retval;
}

/* 通过返回值删除链表数据
 * parameter LinkedNode 头节点地址 索引
 * retval 目标节点数据
 */
int LinkNodeListPopDataViaParameter(LinkedNode *head, int index, datatype *data) {
    int num = LinkedNodeListGetNumberViaCounting(head);
    LinkedNode *p = head, *t;
    if (index >= 0 && index <= num) {
        for (int n = 0; n < index; n++) {
            p = p->next; // 此时p指向待删除节点的前一个地址
        }
        t = p->next;
        *data = t->data;
        p->next = t->next;
        free(t);
        return 1;
    }
    return -1;
}