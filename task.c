#include <stdio.h>
#include <string.h>

int main() {
	int status = VerifyRegex();
	switch (status) {
	case -1: {
		printf("syntax error");
		break;
	}
	case 0: {
		printf("false");
		break;
	}
	case 1: {
		printf("true");
		break;
	}
	default: {
		break;
	}
	}
	return 0;
}

// 该函数实现了字符串与字符规律的输入并实现了校验的功能，返回值为1时表示匹配，
// 0表示不匹配，-1表示格式有误
// 不能校验".*abcd"这种有歧义的正则表达式
int VerifyRegex() {
	char string_input[100], string_regex[100];
	char* p_input = string_input, * p_regex = string_regex;
	scanf("%s%s", string_input, string_regex);
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
						return 0;
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
					return 1;
				}
			}
		} else {
			return -1;
		}
	} while (*p_regex != '\0');
    // 当只有部分字符串匹配时报错
	if (*p_input != '\0') {
		return 0;
	}
	return 1;
}
