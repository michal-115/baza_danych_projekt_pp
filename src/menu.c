#include <stdio.h>
#include "menu.h"
#include "hero.h"
#include "utils.h"
#include "file.h"

void menu(Node** head, const char* filename) {
    int choice;
    char nick[MAX_NAME];
    do {
        printf("\n1.Add\n2.Show\n3.Edit\n4.Remove\n5.Save\n6.Load\n0.Exit\n");
        choice = readInt("Choice: ", 0, 6);

        if (choice == 1) *head = addNode(*head, createHero());
        else if (choice == 2) printList(*head);
        else if (choice == 3) {
            readString("Nickname: ", nick, MAX_NAME);
            Node* n = findByNickname(*head, nick);
            if (n) editHero(&n->data);
        }
        else if (choice == 4) {
            int ok;
            readString("Nickname: ", nick, MAX_NAME);
            *head = removeByNickname(*head, nick, &ok);
        }
        else if (choice == 5) saveToFile(filename, *head);
        else if (choice == 6) {
            freeList(*head);
            *head = loadFromFile(filename);
        }
    } while (choice != 0);
}
