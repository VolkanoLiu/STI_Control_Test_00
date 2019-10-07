#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

bool isMatch(char *s, char *p) {
  int s_length, p_length;
  if ((s_length = strlen(s)) && (p_length = strlen(p))) {
    if (p[p_length - 1] != '*' &&
        (s[s_length - 1] == p[p_length - 1] || p[p_length - 1] == '.')) {
      char sn[MAX_LENGTH], pn[MAX_LENGTH];
      strcpy(sn, s);
      strcpy(pn, p);
      sn[s_length - 1] = '\0';
      pn[p_length - 1] = '\0';
      return isMatch(sn, pn);
    }
    // todo
  }
  // todo
}

int main() {
  char string_input[MAX_LENGTH], string_rule[MAX_LENGTH];
  gets(string_input);
  gets(string_rule);
  return 0;
}
