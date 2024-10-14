#include <stdio.h>
#include "type_valid.h"

// Hàm kiểm tra định dạng số điện thoại
int isValidPhone(char* phoneNumber) {
    int i = 0;

    // Kiểm tra độ dài
    while (phoneNumber[i] != '\0') {
        i++;
    }
    
    if (i != 10) {
        return 0; // Không hợp lệ
    }

    // Kiểm tra từng ký tự
    for (int j = 0; j < 10; j++) {
        if (phoneNumber[j] < '0' || phoneNumber[j] > '9') {
            return 0; // Không hợp lệ
        }
    }

    return 1; // Hợp lệ
}

// Hàm kiểm tra định dạng địa chỉ email
int isValidEmail(char* email) {
     int i = 0;
    int atIndex = -1;

    // Tìm vị trí của ký tự '@'
    while (email[i] != '\0') {
        if (email[i] == '@') {
            if (atIndex == -1) {
                atIndex = i; // Lưu vị trí của '@'
            } else {
                return 0; // Có nhiều ký tự '@'
            }
        }
        i++;
    }

    // Kiểm tra xem có ký tự '@' không và nó không phải là ký tự đầu tiên
    if (atIndex == -1 || atIndex == 0) {
        return 0; // Không hợp lệ
    }

    // Kiểm tra tên miền có phải là 'gmail.com'
    if (email[atIndex + 1] == 'g' && email[atIndex + 2] == 'm' &&
        email[atIndex + 3] == 'a' && email[atIndex + 4] == 'i' &&
        email[atIndex + 5] == 'l' && email[atIndex + 6] == '.' &&
        email[atIndex + 7] == 'c' && email[atIndex + 8] == 'o' &&
        email[atIndex + 9] == 'm' && email[atIndex + 10] == '\0') {
        return 1; // Hợp lệ
    }

    return 0; // Không hợp lệ
}