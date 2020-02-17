#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    char c;
    int small = 0;
    int big = 0;
    int num = 0;
    int space = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("%d %d %d %d\n", small, big, num, space);
            small = 0;
            big = 0;
            num = 0;
            space = 0;
            continue;
        }
        if ('a' <= c && c <= 'z') {
            small++;
        } else if ('A' <= c && c <= 'Z') {
            big++;
        } else if (c == ' ') {
            space++;
        } else {
            num++;
        }
    }
    if (small + big + num + space > 0) {
        printf("%d %d %d %d\n", small, big, num, space);
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}