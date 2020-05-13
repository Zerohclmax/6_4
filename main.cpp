#include <iostream>
#include <cstdio>
#include <cstring>
//链表
const int Maxn = 1000;
int last, cur, next[Maxn];
char s[Maxn];

int main() {
    while (scanf("%s", s + 1) == 1) {
        int n = strlen(s + 1);
        last = cur = 0;
        next[0] = 0;

        for (int i = 1; i <= n; i++) {
            char c = s[i];
            if (c == '[') {
                cur = 0;
            } else if (c == ']') {
                cur = last;
            } else {
                next[i] = next[cur];//插入需求(相当于把【】内的插在开头)!!!!!!!!
                next[cur] = i;
                if (cur == last) {
                    last = i;
                }
                cur = i;//光标移动
            }
        }
        for (int i = next[0]; i != 0; i = next[i]) {//链表，next的索引和值是链表的头和尾!!!!
            printf("%c", s[i]);
        }
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("%d ",next[j]);
        }
    }
    return 0;
}
