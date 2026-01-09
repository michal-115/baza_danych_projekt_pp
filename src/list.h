#ifndef LIST_H
#define LIST_H

#include "hero.h"

typedef struct Node {
    Hero data;
    struct Node* next;
} Node;

Node* addNode(Node* head, Hero h);
Node* removeByNickname(Node* head, const char* nickname, int* success);
Node* findByNickname(Node* head, const char* nickname);
void printList(Node* head);
void freeList(Node* head);

#endif
