/*  
    Chương trình quản lý danh bạ điện thoại
    Thông tin nhập vào: Tên, Số điện thoại, Email, Địa chỉ
    Chức năng: Thêm thông tin, Xoá thông tin, Chỉnh sửa thông tin, Tìm kiếm thông tin
*/
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "contact_manager.h"
#include "user_interface.h"

// Chương trình chính
int main() {
    int option;
    char* file_name = "phoneBook.csv"; // Khai báo tên file lưu trữ

    do {
        menu();
        printf("Chon chuc nang: ");
        scanf("%d", &option);
        system("cls"); // Clear màn hình terminal

        switch (option) {
        case 1: // Thêm thông tin liên lạc
            addInfo(file_name);
            break;
        case 2: // Xoá thông tin liên lạc
            deleteInfo(file_name);
            break;
        case 3: // Sửa thông tin liên lạc
            editInfo(file_name);
            break;
        case 4: // Tìm kiếm thông tin liên lạc
            searchInfo(file_name);
            break;
        case 0: 
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Chon sai chuc nang!!!\n");
            break;
        }
    } while(option != 0);

    return 0;
}