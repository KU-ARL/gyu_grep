// grep.h

#ifndef GREP_H
#define GREP_H

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  // getopt

typedef struct {
    int case_insensitive;   // -i : 대소문자 무시
    int show_line_numbers;  // -n : 발견 line num 출력
    int recursive;          // -r : 디렉토리 내 모든 파일 검색
    int invert_match;       // -v : 일치하지 않는 line 검색 (반전 검색)
    int count_only          // -c : 발견 line 개수만 출력
    // -l : 발견한 파일 이름만 출력
    // -w : 단어 단위로 검색


    const char *pattern;
} grep_config;

// 파일 검색 로직
void search_in_file(const char *pattern, const char *filename, int show_line_numbers, int case_insensitive);



#endif