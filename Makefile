# Tên compiler
CC = gcc

# Tạo danh sách tất cả các file .c trong thư mục hiện tại
SRCS = $(wildcard *.c)

# Tên file thực thi
TARGET = main

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)
	./$(TARGET)