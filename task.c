#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// 该函数实现了字符串与字符规律的输入并实现了校验的功能，返回值为1时表示匹配，
// 0表示不匹配，-1表示格式有误
// 不能校验".*abcd"这种有歧义的正则表达式
bool isMatch(char *s, char *p) {
  char *p_input = s, *p_regex = p;
  if (*s == '\0' || *p == '\0') {
    if (*s == '\0' && *p == '\0') {
      return true;
    } else {
      if (p[0] == '.' && p[1] == '*') {
        return 1;
      } else {
        return 0;
      }
    }
  }
  do {
    // 当正则指针指向的字符不是'*'时，该字符串才是有效的正则表达式。
    // 首先检验当前正则指针指向的字符是一般字符还是'.'，再检验后一位的字符
    // 是不是'*'，再通过正则指针与输入的后移来实现校验的功能。
    if (*p_regex != '*') {
      if (*p_regex != '.') {
        if (*(p_regex + 1) != '*') {
          if (*p_regex == *p_input) {
            p_input++;
            p_regex++;
          } else {
            return false;
          }
        } else {
          while (*p_input == *p_regex) {
            p_input++;
          }
          p_regex += 2;
        }
      } else {
        if (*(p_regex + 1) != '*') {
          p_input++;
          p_regex++;
        } else {
          return true;
        }
      }
    } else {
      return false;
    }
  } while (*p_regex != '\0');
  // 当只有部分字符串匹配时报错
  if (*p_input != '\0') {
    return false;
  }
  return true;
}

int main() {
  char string_input[100], string_regex[100];
  gets(string_input);
  gets(string_regex);
  bool status = isMatch(string_input, string_regex);
  if (status == true) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return 0;
}
