#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void saveToFile(const char* filename, Node* head) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("File error!\n");
        return;
    }
    while (head) {
        Hero* h = &head->data;
        fprintf(f, "%s;%d;%s;%d;%s;%d\n",
            h->nickname, h->role, h->power,
            h->threatLevel, h->district, h->status);
        head = head->next;
    }
    fclose(f);
}

Node* loadFromFile(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("File not found.\n");
        return NULL;
    }
    Node* head = NULL;
    Hero h;
    while (fscanf(f, "%99[^;];%d;%199[^;];%d;%99[^;];%d\n",
        h.nickname, (int*)&h.role, h.power,
        &h.threatLevel, h.district, (int*)&h.status) == 6) {
        head = addNode(head, h);
    }
    fclose(f);
    return head;
}
