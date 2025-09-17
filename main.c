// main.c

#include "grep.h"

int main(int argc, char *argv[]) {

    int opt;
    int show_line_numbers = 0;  // -n 옵션 플래그
    int case_insensitive = 0;   // -i 옵션 플래그

    while ((opt = getopt(argc, argv, "ni")) != -1) {
        switch (opt) {
            case 'n':
                show_line_numbers = 1;
                break;
            case 'i':
                case_insensitive = 1;
                break;
            default:
                fprintf(stderr, "사용법: %s [-ni] <패턴> <파일/디렉토리>\n", argv[0]);
                return 1;
        }
    }

    // optind : getopt가 옵션 파싱을 끝내고 옵션이 아닌 첫 번째 인자(패턴)의 "인덱스"를 가리킴
    if (argc - optind < 2) {
        fprintf(stderr, "사용법: %s [-ni] <패턴> <파일/디렉토리>\n", argv[0]);
        return 1;
    }
    
    const char *pattern = argv[optind];
    const char *filename = argv[optind + 1];


    // 3. 핵심 로직 실행
    search_in_file(pattern, filename, show_line_numbers, case_insensitive);
    
    return 0;
}