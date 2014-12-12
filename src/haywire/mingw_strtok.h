#include <stddef.h> /* NULL Definition */
#define strtok_r  win_strtok_r
#define strtok_s  win_strtok_r

char *win_strtok_r(char *str, const char *delim, char **state);
