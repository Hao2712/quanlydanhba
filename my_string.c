#include <stdio.h>
#include "my_string.h"

// Hàm so sánh chuỗi
int compareString(char *str1, char *str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

// Hàm copy chuỗi source sang chuỗi destination
void copyString(char *destination, char *source) {
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
}

// Hàm đo độ dài chuỗi
int stringLength(char *str) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

// Hàm dịch chuỗi
void stringMove(char *str, int start, int length) {
	int current_length = stringLength(str);

	for(int i = current_length - 1; i >= start; i--) {
	str[i + length] = str[i];
}

for(int i = start; i < start + length; i++) {
	str[i] = ' ';
}

	str[current_length + length] = '\0';
}

// Hàm chèn chuỗi
void insertString(char *dest, char *src, int pos) {
	int dest_len = stringLength(dest);
	int src_len = stringLength(src);

	if(pos > dest_len) {
		return;
	}

	stringMove(dest, pos, src_len + 1);
	string_copy(dest + pos, src);
}

// Hàm string_copy dùng riêng cho insertString
void string_copy(char *dest, char *src) {
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
}

// Hàm xoá chuỗi
void removeSubstring(char *str, int start, int length) {
	int str_len = stringLength(str);

	if (start < 0 || length < 0 || start > str_len) {
		printf("Invalid parameter");
return;
	}
	
	if (start + length > str_len) {
		length = str_len - start;
	}

	for(int i = start + length; i <= str_len; i++) {
		str[i - length] = str[i];
	}

	str[str_len] = '\0';
}

// Hàm tìm chuỗi
int findSubstring(char *to_search, char *to_find) {
	int search_len = stringLength(to_search);
	int find_len = stringLength(to_find);

	if(find_len == 0) {
		return 0;
	}

	if(find_len > search_len) {
		return -1;
	}

	for(int i = 0; i <= search_len - find_len; i++) {
		int j = 0;
		while (j < find_len && to_search[i + j] == to_find[j]) {
			j++;
		}
		if(j == find_len) {
			return i;
		}
	}

	return -1;
}

