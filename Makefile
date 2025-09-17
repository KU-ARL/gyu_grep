# Makefile

# 컴파일러 지정
CC = gcc
# 컴파일 옵션 (-g: 디버깅 정보, -Wall: 모든 경고 표시)
CFLAGS = -g -Wall
# 생성할 실행 파일 이름
TARGET = gyu_grep

# 'make' 라고만 치면 all이 실행됨
all: $(TARGET)

# 실행 파일(TARGET)은 main.o와 functions.o에 의존하며,
# 이 둘을 묶어서(링크해서) 실행 파일을 생성한다.
$(TARGET): main.o functions.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o functions.o

# .c 파일로부터 .o (오브젝트) 파일을 만드는 규칙
main.o: main.c grep.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c grep.h
	$(CC) $(CFLAGS) -c functions.c

# 'make clean'을 실행하면 컴파일된 파일들을 삭제한다.
clean:
	rm -f $(TARGET) *.o