#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "contact_manager.h"
#include "type_valid.h"

void menu();
void information_input(Info *info);
void information_change(Info info[], int i);
int search_option(int option);

#endif