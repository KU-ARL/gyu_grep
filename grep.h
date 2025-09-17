// grep.h

#ifndef GREP_H
#define GREP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 파일 검색 로직
void search_in_file(const char *pattern, const char *filename, int show_line_numbers);



#endif