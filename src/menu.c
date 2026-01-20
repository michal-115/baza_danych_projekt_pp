#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"
#include "hero.h"
#include "utils.h"
#include "file.h"

void menu(Node** head, const char* filename) {
    int choice;
    char nick[MAX_NAME];
    do {
        printf("\n--- SUPERHERO DATABASE ---\n");
        printf("1. Add character\n2. Show all\n3. Edit character\n4. Remove character\n");
        printf("5. Save to file\n6. Load from file\n7. Sort alphabetically (Nick)\n8. Sort by threat level\n0. Exit\n");
        choice = readInt("Choice: ", 0, 8);

        if (choice == 1) {
            *head = addNode(*head, createHero());
        }
        else if (choice == 2) {
            printList(*head);
        }
        else if (choice == 3) {
            readString("Enter Nickname to edit: ", nick, MAX_NAME);
            Node* n = findByNickname(*head, nick);
            if (n) editHero(&n->data);
            else printf("Character not found.\n");
        }
        else if (choice == 4) {
            int ok;
            readString("Enter Nickname to remove: ", nick, MAX_NAME);
            *head = removeByNickname(*head, nick, &ok);
            if (ok) printf("Successfully removed.\n");
            else printf("Removal failed (character not found or is imprisoned).\n");
        }
        else if (choice == 5) {
            saveToFile(filename, *head);
            printf("Data saved successfully.\n");
        }
        else if (choice == 6) {
            Node* newList = loadFromFile(filename);
            if (newList != NULL) {
                freeList(*head);
                *head = newList;
                printf("Data loaded successfully.\n");
            }
        }
        else if (choice == 7) {
            sortList(*head, 0);
        }
        else if (choice == 8) {
            sortList(*head, 1);
        }

    } while (choice != 0);
}