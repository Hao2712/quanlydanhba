#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

// Struct để lưu thông tin của một số điện thoại
typedef struct {
    char name[50]; // Tên
    char phoneNumber[11]; // Số điện thoại
    char email[50]; // Địa chỉ email
    char address[256]; // Địa chỉ
} Info;

void addInfo(char* file_name);
void deleteInfo(char* file_name);
void editInfo(char* file_name);
void searchInfo(char* file_name);
void press_key();

#endif