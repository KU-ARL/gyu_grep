// main.c

#include "grep.h"

int main(int argc, char *argv[]) {
    // 1. 인자 개수 확인: [프로그램이름, 패턴, 파일]
    if (argc < 3) {
        fprintf(stderr, "사용법: %s [옵션] <검색패턴> <파일명>\n", argv[0]);
        return 1; // 에러 코드로 종료
    }

    // 2. 옵션, 패턴, 파일 이름 파싱
    const char *pattern;
    const char *filename;
    int show_line_numbers = 0; // -n 옵션 플래그

    if (strcmp(argv[1], "-n") == 0) {
        if (argc < 4) { // -n 옵션 사용 시 인자가 4개여야 함
            fprintf(stderr, "사용법: %s [-n] <검색패턴> <파일명>\n", argv[0]);
            return 1;
        }
        show_line_numbers = 1;
        pattern = argv[2];
        filename = argv[3];
    } else { // 옵션이 없는 경우
        pattern = argv[1];
        filename = argv[2];
    }
    // 3. 핵심 로직 실행
    search_in_file(pattern, filename, show_line_numbers);
    
    return 0;
}