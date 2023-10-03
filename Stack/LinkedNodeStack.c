#include "LinkedNodeStack.h"

LinkedNode *LinkedNodeStackInit() {
    LinkedNode *head, *t, *p;
    head = (LinkedNode*)malloc(sizeof(LinkedNode));
    head->next = NULL;
    return head;
}

LinkedNode *LinkedNodeStackGetFirst(LinkedNode *head) {
    return head->next;
}

int LinkedNodeStackGetNumberViaCounting(LinkedNode *head) {
    LinkedNode *p = LinkedNodeStackGetFirst(head);
    int num = 0;
    for (; p != NULL; p = p->next) {
        num++;
    }
    return num;
}

LinkedNode *LinkedNodeStackGetLast(LinkedNode *head) {
    LinkedNode *p = head;
    for (; p->next != NULL; p = p->next);
    return p;
}

LinkedNode *LinkedNodeStackGetSecondLast(LinkedNode *head) {
    LinkedNode *p = head;
    for (; p->next->next != NULL; p = p->next);
    return p;
}

int LinkedNodeStackInsertData(LinkedNode *head, const datatype data) {
    LinkedNode *last = LinkedNodeStackGetLast(head);
    LinkedNode *new_node = (LinkedNode *)malloc(sizeof(LinkedNode));
    if (new_node == NULL) {
        return -1;
    }
    new_node->next = NULL;
    new_node->data = data;
    last->next = new_node;
    return 1;
}

datatype LinkedNodeStackPopDataViaReturnValue(LinkedNode *head) {
    datatype retval;
    int num = LinkedNodeStackGetNumberViaCounting(head);
    if (num == 1) {
        retval = head->next->data;
        head->next = NULL;
    }else if (num != 0) {
        LinkedNode *t = LinkedNodeStackGetSecondLast(head);
        retval = t->next->data;
        free(t->next);
        t->next = NULL;
    }
    return retval;
}

int LinkedNodeStackPopDataViaParameter(LinkedNode *head, datatype *data) {
    int num = LinkedNodeStackGetNumberViaCounting(head);
    if (num == 1) {
        *data = head->next->data;
        head->next = NULL;
        return 1;
    }else if (num != 0) {
        LinkedNode *t = LinkedNodeStackGetSecondLast(head);
        *data = t->next->data;
        free(t->next);
        t->next = NULL;
        return 1;
    }
    return -1;
}

