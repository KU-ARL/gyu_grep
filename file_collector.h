#ifndef FILE_COLLECTOR_H
#define FILE_COLLECTOR_H

#include "grep.h"

typedef struct {
    char **paths;
    int count;
} file_list;

// 주어진 경로와 설정에 따라 파일 목록을 수집하는 함수
file_list* collect_files(const char *path, const grep_config *config);

// 수집된 파일 목록에 할당된 메모리를 해제하는 함수
void free_file_list(file_list *list);

#endif