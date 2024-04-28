#pragma once

#include <coroutine>
#include <iostream>
#include <stdio.h>

#define print_title() printf("%-10s    %-4s    %s\n", "FILE", "LINE", "SYMBOL")

#define print_line_func()                                                      \
  printf("F: %-10s L: %-4d S: %s\n", SRCNAME, __LINE__, __FUNCTION__)
