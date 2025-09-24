// main.c

#include "grep.h"
#include "file_collector.h"
#include "file_pocessor.h"

int main(int argc, char *argv[]) {
    // 1. 설정(config) 객체 생성 및 초기화
    grep_config config = {0}; // 모든 플래그를 0으로 초기화

    int opt;

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

    // 3. 패턴과 경로 설정

    // optind : getopt가 옵션 파싱을 끝내고 옵션이 아닌 첫 번째 인자(패턴)의 "인덱스"를 가리킴
    if (argc - optind < 2) {
        fprintf(stderr, "사용법: %s [-ni] <패턴> <파일/디렉토리>\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[optind];
    const char *path = argv[optind + 1];
    config.pattern = pattern;


    // 4. [계층 1] 파일 수집기 호출
    file_list *files = collect_files(path, &config);
    if (files == NULL) {
        return 1; // 오류 처리
    }

    // 5. [계층 2] 파일 처리기 호출
    process_files(files, &config);

    // 6. 메모리 해제
    free_file_list(files);
    
    return 0;
}