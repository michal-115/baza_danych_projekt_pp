#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Node* addNode(Node* head, Hero h) {
    Node* n = malloc(sizeof(Node));
    n->data = h;
    n->next = head;
    return n;
}

Node* findByNickname(Node* head, const char* nickname) {
    while (head) {
        if (strcmp(head->data.nickname, nickname) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

Node* removeByNickname(Node* head, const char* nickname, int* success) {
    Node* curr = head, * prev = NULL;
    *success = 0;

    while (curr) {
        if (strcmp(curr->data.nickname, nickname) == 0) {
            if (curr->data.status == IMPRISONED) {
                printf("Cannot remove imprisoned character!\n");
                return head;
            }
            if (prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
            *success = 1;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    printf("Nickname        | Role       | Threat     | District        | Status       | Power\n");
    printf("-------------------------------------------------------------------------------------\n");
    while (head) {
        printHero(&head->data);
        head = head->next;
    }
}

void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}
