#pragma once
#include <cassert>

#if __INTELLISENSE__
#pragma diag_suppress 2486
#endif
#define DEBUG_MODE
#include<stdio.h>
#ifdef DEBUG_MODE
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_BOLD_RED     "\x1b[1;31m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_BOLD_GREEN   "\x1b[1;32m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_BOLD_YELLOW  "\x1b[1;33m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_COLOR_BOLD_BLUE    "\x1b[1;34m"
#define ANSI_COLOR_MAGENTA      "\x1b[35m"
#define ANSI_COLOR_BOLD_MAGENTA "\x1b[1;35m"
#define ANSI_COLOR_CYAN         "\x1b[36m"
#define ANSI_COLOR_BOLD_CYAN    "\x1b[1;36m"
#define ANSI_COLOR_RESET        "\x1b[0m"

#define STR_FROM_INT(x) #x
#define STR(x) STR_FROM_INT(x)
#define test(...) printf(ANSI_COLOR_BOLD_RED "TEST::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_RED __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define ERROR(...) printf(ANSI_COLOR_BOLD_RED "ERROR::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_RED __VA_ARGS__); printf(ANSI_COLOR_RESET "\n"); assert(false)
#define LOG(...) printf(ANSI_COLOR_BOLD_CYAN "LOG::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_CYAN __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define DEBUG(...) printf(ANSI_COLOR_BOLD_GREEN "LOG::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_GREEN __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define WARN(...) printf(ANSI_COLOR_BOLD_YELLOW "WARN::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_YELLOW __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define INIT_LOG(...) printf(ANSI_COLOR_BOLD_BLUE "INIT::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_BLUE __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#define UNLOAD_LOG(...) printf(ANSI_COLOR_BOLD_MAGENTA "UNLOAD::" __FILE__ ":" STR(__LINE__) "\t" ANSI_COLOR_RESET ANSI_COLOR_MAGENTA __VA_ARGS__); printf(ANSI_COLOR_RESET "\n")
#endif