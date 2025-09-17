// functions.c

#include "grep.h"

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