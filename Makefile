# Tên của file thực thi
TARGET = quanlydanhba

# Trình biên dịch
CC = gcc

# Cờ biên dịch
CFLAGS = -Wall -g

# Các file nguồn
SRCS = quanlydanhba.c contact_manager.c my_string.c type_valid.c user_interface.c

# Các file object được tạo từ các file nguồn
OBJS = $(SRCS:.c=.o)

# Quy tắc để tạo file thực thi từ các file object
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Quy tắc để biên dịch các file .c thành file .o
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run clean
# Quy tắc để chạy file thực thi
run: $(TARGET)
	./$(TARGET)

# Quy tắc để dọn dẹp các file biên dịch
clean:
	rm -f $(OBJS) $(TARGET)
