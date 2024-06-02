#ifndef __STRSPLT_GRUMGOG__
#define __STRSPLT_GRUMGOG__
#include <string.h>
#include <stdbool.h>

bool
strsplt_r(char **dst, char *str, const char *substr, char **last);

bool
strsplt(char **dst, char *str, const char *substr);

#endif