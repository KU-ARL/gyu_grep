# Makefile

# 컴파일러 지정
CC = gcc
# 컴파일 옵션 (-g: 디버깅 정보, -Wall: 모든 경고 표시)
CFLAGS = -g -Wall
# 생성할 실행 파일 이름
TARGET = gyu_grep

# 오브젝트 파일 목록
OBJS = main.o file_collector.o file_processor.o

# 'make' 라고만 치면 all이 실행됨
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c grep.h file_collector.h file_processor.h
	$(CC) $(CFLAGS) -c main.c

file_collector.o: file_collector.c file_collector.h grep.h
	$(CC) $(CFLAGS) -c file_collector.c

file_processor.o: file_processor.c file_processor.h grep.h file_collector.h
	$(CC) $(CFLAGS) -c file_processor.c

clean:
	rm -f $(TARGET) *.o

# test: $(TARGET)
# 	./$(TARGET) -n "void" test.c