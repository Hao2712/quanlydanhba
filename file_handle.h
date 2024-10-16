#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H
#include "contact_manager.h"
#include <stdio.h>

FILE *open_file(char* file_name, char* mode);
int scan_file(char* file_name, Info info[], int count);  

#endif