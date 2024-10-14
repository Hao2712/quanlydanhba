#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "contact_manager.h"
#include "my_string.h"
#include "type_valid.h"

// Hàm thêm thông tin
void addInfo(char* file_name) {
    FILE *file = fopen(file_name, "a"); 

    if(file == NULL) {
        printf("Khong the mo file\n");
        return;
    }

    Info info;
    int phoneCheck = 1; // Biến kiểm tra định dạng số điện thoại
    int emailCheck = 1; // Biến kiểm tra định dạng email

    // Nhập thông tin
    printf("Ten: ");
    scanf(" %[^\n]", info.name); // %[^\n] lấy tất cả dữ liệu nhập vào ngoại trừ xuống dòng
    printf("So dien thoai: ");
    scanf("%s", info.phoneNumber);
    phoneCheck = isValidPhone(info.phoneNumber);
    while(phoneCheck == 0) { // Yêu cầu người dùng nhập đúng định dạng
        printf("So dien thoai sai dinh dang\n");
        printf("Nhap lai so dien thoai: ");
        scanf("%s", info.phoneNumber);
        phoneCheck = isValidPhone(info.phoneNumber);
    }
    printf("Email: ");
    scanf("%s", info.email);
    emailCheck = isValidEmail(info.email);
    while (emailCheck == 0) { // Yêu cầu người dùng nhập đúng định dạng
        printf("Email sai dinh dang\n");
        printf("Nhap lai Email: ");
        scanf("%s", info.email);
        emailCheck = isValidEmail(info.email);
    }
    printf("Dia chi: ");
    scanf(" %[^\n]", info.address); // %[^\n] lấy tất cả dữ liệu nhập vào ngoại trừ xuống dòng

    fprintf(file, "%s,%s,%s,%s\n", info.name, info.phoneNumber, info.email, info.address); // Ghi dữ liệu vào file

    fclose(file);
    printf("Them thong tin thanh cong.");
    Sleep(1000); // Delay 1s
    system("cls"); // Clear màn hình terminal
}

// Hàm xoá thông tin
void deleteInfo(char* file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    Info info[1000]; // Tạo mảng với kiểu dữ liệu Info
    int count = 0; // Đếm số dòng trong file
    char numberToDelete[11]; // Biến tham số đầu vào để xoá thông tin

    printf("Nhap so dien thoai can xoa: ");
    scanf("%s", numberToDelete);

    // Quét dữ liệu trong file lưu vào mảng 
    // %[^,] quét tất cả dữ liệu tới dấu ',' thì ngừng. Số nguyên đứng trước cho biết phần tử tối đa mà fscanf sẽ quét
    while(fscanf(file, "%49[^,],%10[^,],%49[^,],%255[^\n]\n", info[count].name, info[count].phoneNumber, info[count].email, info[count].address) != EOF) {
        count++;
    }

    fclose(file);

    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

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
    } else {
        printf("Khong tim thay so dien thoai %s.\n", numberToDelete);
    }
    Sleep(1000); // Delay 1s
    system("cls"); // Clear màn hình terminal
}

// Hàm thay đổi thông tin
void editInfo(char* file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    Info info[1000]; // Tạo mảng với kiểu dữ liệu Info
    int count = 0; // Đếm số dòng trong file
    char numberToEdit[11]; // Biến tham số đầu vào để thay đổi thông tin

    printf("Nhap so dien thoai can thay doi thong tin: ");
    scanf("%s", numberToEdit);

    // Quét dữ liệu trong file lưu vào mảng 
    // %[^,] quét tất cả dữ liệu tới dấu ',' thì ngừng. Số nguyên đứng trước cho biết phần tử tối đa mà fscanf sẽ quét
    while(fscanf(file, "%49[^,],%10[^,],%49[^,],%255[^\n]\n", info[count].name, info[count].phoneNumber, info[count].email, info[count].address) != EOF) {
        count++;
    }

    fclose(file);

    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    int edited = 0;
    for (int i = 0; i < count; i++) {
        int result = compareString(info[i].phoneNumber, numberToEdit);
        if (result != 0) {
            fprintf(file, "%s,%s,%s,%s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
        } else {
            // Thay đổi thông tin
            int emailCheck = 1; // Biến kiểm tra định dạng email
            printf("Ten: ");
            scanf(" %[^\n]", info[i].name); // %[^\n] lấy tất cả dữ liệu nhập vào ngoại trừ xuống dòng
            printf("Email: ");
            scanf("%s", info[i].email);
            emailCheck = isValidEmail(info[i].email);
            while (emailCheck == 0) { // Yêu cầu người dùng nhập đúng định dạng
                printf("Email sai dinh dang\n");
                printf("Nhap lai Email: ");
                scanf("%s", info[i].email);
                emailCheck = isValidEmail(info[i].email);
            }
            printf("Dia chi: ");
            scanf(" %[^\n]", info[i].address); // %[^\n] lấy tất cả dữ liệu nhập vào ngoại trừ xuống dòng
    
            fprintf(file, "%s,%s,%s,%s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
            edited = 1;
        }
    }
    fclose(file);

    if (edited) {
        printf("Da cap nhat thong tin so dien thoai %s thanh cong!\n", numberToEdit);
    } else {
        printf("Khong tim thay so dien thoai %s.\n", numberToEdit);
    }
    Sleep(1000); // Delay 1s
    system("cls"); // Clear màn hình terminal
}

// Hàm tìm kiếm thông tin
void searchInfo(char* file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    Info info[1000]; // Tạo mảng với kiểu dữ liệu Info
    int count = 0; // Biến đếm số dòng trong file
    char numberToDisplay[11]; // Biến tham số đầu vào nếu hiển thị theo số điện thoại
    char nameToDisplay[50]; // Biến tham số đầu vào nếu hiển thị theo tên
    int option;

    printf("Tim kiem theo:\n");
    printf("1. Ten\n");
    printf("2. So dien thoai\n");
    printf("Chon chuc nang: ");
    scanf("%d", &option);
    if(option == 1) {
        printf("Nhap ten: ");
        scanf(" %[^\n]", nameToDisplay); // %[^\n] lấy tất cả dữ liệu nhập vào ngoại trừ xuống dòng
    } else {
        printf("Nhap so dien thoai: ");
        scanf("%s", numberToDisplay);
    }
    
    // Quét dữ liệu trong file lưu vào mảng 
    // %[^,] quét tất cả dữ liệu tới dấu ',' thì ngừng. Số nguyên đứng trước cho biết phần tử tối đa mà fscanf sẽ quét
    while(fscanf(file, "%49[^,],%10[^,],%49[^,],%255[^\n]\n", info[count].name, info[count].phoneNumber, info[count].email, info[count].address) != EOF) {
        count++;
    }

    fclose(file);

    int display = 0;
    for(int i = 0; i < count; i++) {
        if(option == 1) {
            int result = compareString(nameToDisplay, info[i].name);
            if(result == 0) {
                printf("Ten: %s, So dien thoai: %s, Email: %s, Dia chi: %s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
                getch(); // Màn hình terminal giữ nguyên đến khi nhận được tín hiệu từ bàn phím
                display = 1;
            }
        } else {
            int result = compareString(numberToDisplay, info[i].phoneNumber);
            if(result == 0) {
                printf("Ten: %s, So dien thoai: %s, Email: %s, Dia chi: %s\n", info[i].name, info[i].phoneNumber, info[i].email, info[i].address);
                getch(); // Màn hình terminal giữ nguyên đến khi nhận được tín hiệu từ bàn phím
                display = 1;
            }
        }
    }

    fclose(file);

    if (display == 0) {
        if(option == 1) {
            printf("Khong tim thay thong tin voi ten %s", nameToDisplay);
        } else {
            printf("Khong tim thay thong tin voi so dien thoai %s", numberToDisplay);
        }
    }
    Sleep(1000); // Delay 1s
    system("cls"); // Clear màn hình terminal
}