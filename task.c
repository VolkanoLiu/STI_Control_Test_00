#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

bool isMatch(char *s, char *p) {
  int s_length = strlen(s), p_length = strlen(p);
  // if s is empty
  if (s_length == 0) {
    if (p_length == 0) {
      return true;
    } else if (p_length >= 2 && p[1] == '*') {
      return isMatch(s, p + 2);
    } else {
      return false;
    }
  }
  // if p is empty
  if (p_length == 0) {
    return s_length == 0;
  }
  // if p_length >= 2 and p[1] == '*'
  if (p_length >= 2 && p[1] == '*') {
    // if one of the expressions returns true, this function will return true.
    return isMatch(s, p + 2) ||
           ((s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p));
  }
  // if p[1] is not '*' and p[0] matches s[0]
  if (s[0] == p[0] || p[0] == '.') {
    return isMatch(s + 1, p + 1);
  } else {
    return false;
  }
}

int main() {
  char string_input[MAX_LENGTH], string_rule[MAX_LENGTH];
  gets(string_input);
  gets(string_rule);
  printf("%d\n", isMatch(string_input, string_rule));
  return 0;
}
