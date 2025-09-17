// grep.h

#ifndef GREP_H
#define GREP_H

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  // getopt

// 파일 검색 로직
void search_in_file(const char *pattern, const char *filename, int show_line_numbers, int case_insensitive);



#endif