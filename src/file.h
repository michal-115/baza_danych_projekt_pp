#ifndef FILE_H
#define FILE_H

#include "list.h"

void saveToFile(const char* filename, Node* head);
Node* loadFromFile(const char* filename);

#endif
