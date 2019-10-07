#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
#define CREATE_NEW_ARRAY               \
  char sn[MAX_LENGTH], pn[MAX_LENGTH]; \
  strcpy(sn, s);                       \
  strcpy(pn, p)

bool isMatch(char *s, char *p) {
  int s_length, p_length;
  if (p_length = strlen(p)) {
    if (s_length = strlen(s)) {
      if (p[p_length - 1] != '*') {
        if (!(p[p_length - 1] != '.' && s[s_length - 1] != p[p_length])) {
          CREATE_NEW_ARRAY;
          sn[s_length - 1] = '\0';
          pn[p_length - 1] = '\0';
          return isMatch(sn, pn);
        } else {
          return false;
        }
      } else {
        if (p[p_length - 2] != '.') {
          CREATE_NEW_ARRAY;
          if (s[s_length - 1 == p[p_length - 2]]) {
            sn[s_length - 1] = '\0';
          } else {
            pn[p_length - 2] = '\0';
          }
          return isMatch(sn, pn);
        } else {
          // todo
        }
      }
    } else {
      if (p[p_length - 1] != '*') {
        return false;
      } else {
        CREATE_NEW_ARRAY;
        pn[p_length - 2] = '\0';
        return isMatch(sn, pn);
      }
    }
  } else {
    if (strlen(s)) {
      return false;
    } else {
      return true;
    }
  }
}

int main() {
  char string_input[MAX_LENGTH], string_rule[MAX_LENGTH];
  gets(string_input);
  gets(string_rule);
  return 0;
}
