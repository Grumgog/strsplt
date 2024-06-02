#include "strsplt.h"

bool
strsplt_r(char **dst, char *str, const char *substr, char **last) {
  if (dst == NULL || substr == NULL) {
    return false;
  }
  
  if (str != NULL) {
    *last = str;
  }
  
  if (*last == NULL) {
	  return false;
  }
  
  char *occ = strstr(*last, substr);
  if (occ == NULL) {
    if (str == NULL && **last != '\0') {
       strncpy(*dst, *last, strlen(*last));
       *last = NULL;
       return true;
    }
    return false;
  }

  int len = occ - *last;
  strncpy(*dst, *last, len);
  *((*dst)+len) = '\0';
  *last = occ + strlen(substr);
  return true;
}

bool
strsplt(char **dst, char *str, const char *substr) {
  static char *last;
  return strsplt_r(dst, str, substr, &last);
}