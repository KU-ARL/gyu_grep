#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include "grep.h"
#include "file_collector.h"

// 각 줄을 처리하는 헬퍼 함수
static void process_line(const char *line, int line_num, const grep_config *config);
// 전체 파일 목록을 받아 순회하며 검색을 수행하는 메인 함수
void process_files(const file_list *list, const grep_config *config);

#endif