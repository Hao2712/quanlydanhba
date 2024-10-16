#include <stdio.h>
#include "file_handle.h"

FILE *open_file(char* file_name, char* mode) {
    FILE *file = fopen(file_name, mode);
    if (file == NULL) {
        printf("Khong the mo file");
        return NULL;
    }

    return file;
}

int scan_file(char* file_name, Info info[], int count) {
    FILE *file = open_file(file_name, "r");

    // %[^,] quét tất cả dữ liệu tới dấu ',' thì ngừng. Số nguyên đứng trước cho biết phần tử tối đa mà fscanf sẽ quét
    while(fscanf(file, "%49[^,],%10[^,],%49[^,],%255[^\n]\n", info[count].name, info[count].phoneNumber, info[count].email, info[count].address) != EOF) {
        count++;
    }

    fclose(file);
    return count;
}