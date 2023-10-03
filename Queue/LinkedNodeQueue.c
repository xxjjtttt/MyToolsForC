#include "LinkedNodeQueue.h"

LinkedNode *LinkedNodeQueueInit() {
    LinkedNode *head, *t, *p;
    head = (LinkedNode*)malloc(sizeof(LinkedNode));
    head->next = NULL;
    return head;
}


LinkedNode *LinkedNodeQueueGetFirst(LinkedNode *head) {
    return head->next;
}

LinkedNode *LinkedNodeQueueGetLast(LinkedNode *head) {
    LinkedNode *p = head;
    for (; p->next != NULL; p = p->next);
    return p;
}

int LinkedNodeQueueGetNumberViaCounting(LinkedNode *head) {
    LinkedNode *p = LinkedNodeQueueGetFirst(head);
    int num = 0;
    for (; p != NULL; p = p->next) {
        num++;
    }
    return num;
}

int LinkedNodeQueueInsertData(LinkedNode *head, const datatype data) {
    LinkedNode *last = LinkedNodeQueueGetLast(head);
    LinkedNode *new_node = (LinkedNode *)malloc(sizeof(LinkedNode));
    if (new_node == NULL) {
        return -1;
    }
    new_node->next = NULL;
    new_node->data = data;
    last->next = new_node;
    return 1;
}

datatype LinkedNodeQueuePopDataViaReturnValue(LinkedNode *head) {
    datatype retval;
    LinkedNode *first = LinkedNodeQueueGetFirst(head);
    if (first != NULL) {
        head->next = first->next;
        retval = first->data;
        free(first);
    }
    return retval;
}

int LinkedNodeQueuePopDataViaParameter(LinkedNode *head, datatype *data) {
    LinkedNode *first = LinkedNodeQueueGetFirst(head);
    if (first != NULL) {
        head->next = first->next;
        *data = first->data;
        free(first);
        return 1;
    }
    return -1;
}
