#include <stdio.h>
#include "user_interface.h"

// Giao diện chương trình
void menu() {
    printf("He thong quan ly danh ba\n");
    printf("------------------------\n");
    printf("1. Them thong tin lien lac\n");
    printf("2. Xoa thong tin lien lac\n"); 
    printf("3. Sua thong tin lien lac\n");
    printf("4. Tim kiem thong tin lien lac\n");
    printf("0. Thoat chuong trinh\n");
}

void information_input(Info *info) {
    int phoneCheck = 1; // Biến kiểm tra định dạng số điện thoại
    int emailCheck = 1; // Biến kiểm tra định dạng email

    printf("Ten: ");
    scanf(" %[^\n]", info->name); // %[^\n] lấy tất cả dữ liệu nhập vào ngoại trừ xuống dòng
    printf("So dien thoai: ");
    scanf("%s", info->phoneNumber);
    phoneCheck = isValidPhone(info->phoneNumber);
    while(phoneCheck == 0) { // Yêu cầu người dùng nhập đúng định dạng
        printf("So dien thoai sai dinh dang\n");
        printf("Nhap lai so dien thoai: ");
        scanf("%s", info->phoneNumber);
        phoneCheck = isValidPhone(info->phoneNumber);
    }
    printf("Email: ");
    scanf("%s", info->email);
    emailCheck = isValidEmail(info->email);
    while (emailCheck == 0) { // Yêu cầu người dùng nhập đúng định dạng
        printf("Email sai dinh dang\n");
        printf("Nhap lai Email: ");
        scanf("%s", info->email);
        emailCheck = isValidEmail(info->email);
    }
    printf("Dia chi: ");
    scanf(" %[^\n]", info->address); // %[^\n] lấy tất cả dữ liệu nhập vào ngoại trừ xuống dòng
}

void information_change(Info info[], int i) {
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
}

int search_option(int option) {
    printf("Tim kiem theo:\n");
    printf("1. Ten\n");
    printf("2. So dien thoai\n");
    printf("Chon chuc nang: ");
    scanf("%d", &option);

    return option;
}