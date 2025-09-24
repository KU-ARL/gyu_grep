#include "file_processor.h"


// 각 줄을 처리하는 헬퍼 함수
static void process_line(const char *line, int line_num, const grep_config *config) {
    // 라인 처리 로직 (검색 및 출력)
}

// 전체 파일을 받아서 하나하나 처리
void process_files(const file_list *list, const grep_config *config) [

];




/*
// 기존 코드
void search_in_file(const char *pattern, const char *filename, int show_line_numbers, int case_insensitive) {
    FILE *fp=fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        return;
    }

    char line[1024];
    int line_num = 1;

    while (fgets(line, sizeof(line), fp) != NULL) {     // TODO : mmap 방법도 도전해보기

        char *match;
        
        if (case_insensitive) {
            match = strcasestr(line, pattern);     // strcasestr : 대소문자 구분 X
        } else {
            match = strstr(line, pattern);        // strstr : 대소문자 구분
        }

        if (match != NULL) {
            if (show_line_numbers) {
                printf("\x1b[33m%d\x1b[0m: %.*s", line_num, (int)(match - line), line);
                printf("\x1b[31m%.*s\x1b[0m", (int)strlen(pattern), match);
                printf("%s", match + strlen(pattern));
            } else {
                printf("%.*s", (int)(match - line), line);
                printf("\x1b[31m%.*s\x1b[0m", (int)strlen(pattern), match);
                printf("%s", match + strlen(pattern));
            }
        }
        line_num++;
    }

    fclose(fp);

}

*/