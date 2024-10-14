#ifndef MY_STRING_H
#define MY_STRING_H

int compareString(char *str1, char *str2);
void copyString(char *destination, char *source);
int stringLength(char *str);
void stringMove(char *str, int start, int length);
void insertString(char *dest, char *src, int pos);
void string_copy(char *dest, char *src);
void removeSubstring(char *str, int start, int length);
int findSubstring(char *to_search, char *to_find);

#endif