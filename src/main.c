#include <stdio.h>
#include "menu.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    Node* head = NULL;
    menu(&head, argv[1]);
    freeList(head);
    return 0;
}
