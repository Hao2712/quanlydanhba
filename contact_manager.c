#include <stdio.h>
#include <stdlib.h>
#include "contact_manager.h"
#include "my_string.h"
#include "type_valid.h"
#include "file_handle.h"
#include "user_interface.h"

// Hàm thêm thông tin
void addInfo(char* file_name) {
    FILE *file = open_file(file_name, "a");

    Info info;
    
    information_input(&info);

    fprintf(file, "%s,%s,%s,%s\n", info.name, info.phoneNumber, info.email, info.address); // Ghi dữ liệu vào file

    fclose(file);
    printf("Them thong tin thanh cong\n");
    press_key();
}

// Hàm xoá thông tin
void deleteInfo(char* file_name) {
    Info info[1000]; // Tạo mảng với kiểu dữ liệu Info
    int count = 0; // Đếm số dòng trong file
    char numberToDelete[11]; // Biến tham số đầu vào để xoá thông tin

    printf("Nhap so dien thoai can xoa: ");
    scanf("%s", numberToDelete);

    // Quét dữ liệu trong file lưu vào mảng 
    count = scan_file(file_name, info, count);

    FILE *file = open_file(file_name, "w");
    
    int deleted = 0;
    for (int i = 0; i < count; i++) {
        int result = compareString(info[i].phoneNumber, numberToDelete); 
        if (result != 0) {
            fprintf(file, "%s,%s,%s,%s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
        } else {
            deleted = 1; // Bỏ qua dòng cần xoá 
        }
    }
    fclose(file);

    if (deleted) {
        printf("Da xoa thong tin so dien thoai %s thanh cong!\n", numberToDelete);
        press_key();
    } else {
        printf("Khong tim thay so dien thoai %s.\n", numberToDelete);
        press_key();
    }
}

// Hàm thay đổi thông tin
void editInfo(char* file_name) {
    Info info[1000]; // Tạo mảng với kiểu dữ liệu Info
    int count = 0; // Đếm số dòng trong file
    char numberToEdit[11]; // Biến tham số đầu vào để thay đổi thông tin

    printf("Nhap so dien thoai can thay doi thong tin: ");
    scanf("%s", numberToEdit);

    // Quét dữ liệu trong file lưu vào mảng 
    count = scan_file(file_name, info, count);

    FILE *file = open_file(file_name, "w");

    int edited = 0;
    for (int i = 0; i < count; i++) {
        int result = compareString(info[i].phoneNumber, numberToEdit);
        if (result != 0) {
            fprintf(file, "%s,%s,%s,%s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
        } else {
            information_change(info, i);
    
            fprintf(file, "%s,%s,%s,%s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
            edited = 1;
        }
    }
    fclose(file);

    if (edited) {
        printf("Da cap nhat thong tin so dien thoai %s thanh cong!\n", numberToEdit);
        press_key();
    } else {
        printf("Khong tim thay so dien thoai %s.\n", numberToEdit);
        press_key();
    }
}

// Hàm tìm kiếm thông tin
void searchInfo(char* file_name) {
    Info info[1000]; // Tạo mảng với kiểu dữ liệu Info
    int count = 0; // Biến đếm số dòng trong file
    char numberToDisplay[11]; // Biến tham số đầu vào nếu hiển thị theo số điện thoại
    char nameToDisplay[50]; // Biến tham số đầu vào nếu hiển thị theo tên
    int option;

    option = search_option(option);

    if(option == 1) {
        printf("Nhap ten: ");
        scanf(" %[^\n]", nameToDisplay); // %[^\n] lấy tất cả dữ liệu nhập vào ngoại trừ xuống dòng
    } else {
        printf("Nhap so dien thoai: ");
        scanf("%s", numberToDisplay);
    }
    
    // Quét dữ liệu trong file lưu vào mảng 
    count = scan_file(file_name, info, count);

    int display = 0;
    for(int i = 0; i < count; i++) {
        if(option == 1) {
            int result = compareString(nameToDisplay, info[i].name);
            if(result == 0) {
                printf("Ten: %s, So dien thoai: %s, Email: %s, Dia chi: %s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
                display = 1;
                press_key();
            }
        } else {
            int result = compareString(numberToDisplay, info[i].phoneNumber);
            if(result == 0) {
                printf("Ten: %s, So dien thoai: %s, Email: %s, Dia chi: %s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
                display = 1;
                press_key();
            }
        }
    }

    if (display == 0) {
        if(option == 1) {
            printf("Khong tim thay thong tin voi ten %s\n", nameToDisplay);
            press_key();
        } else {
            printf("Khong tim thay thong tin voi so dien thoai %s\n", numberToDisplay);
            press_key();
        }
    }
}

void press_key() {
    char key;
    printf("Press any key to continue\n");
    // Đợi cho đến khi người dùng nhập một ký tự hợp lệ
    while ((key = getchar()) != '\n' && key != EOF) {
        // Chỉ cần đọc và bỏ qua ký tự cho đến khi gặp newline
    }
    // Nhận ký tự đầu tiên hợp lệ
    getchar(); // Nhận ký tự bất kỳ từ người dùng
}