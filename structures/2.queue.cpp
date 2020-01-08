#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int m, s, top, down;
char ch;

int *resizing(int *st) {
    auto *new_st = (int*) malloc((size_t) s * sizeof(int));
    for (int i = down; i < top; i++) {
        new_st[i] = st[i];
    }
    free(st);
    return new_st;
}

int main() {
   freopen("queue.in", "r", stdin);
   freopen("queue.out", "w", stdout);
    ios_base::sync_with_stdio(0);

    cin >> m;
    s = 1; top = 0; down = 0;
    auto *st = (int*) malloc((size_t) s * sizeof(int));
    for (int i = 0; i < m; i++) {
        cin >> ch;
        if ((top) == s) {
            s *= 2;
            st = resizing(st);
        }
        if ((s > 1) && ((top)* 4 <= s)) {
            s /= 2;
            st = resizing(st);
            top -= down; down = 0;
        }
        if (ch == '+') {
            cin >> st[top];
            ++top;
        } else {
            cout << st[down] << '\n'; ++down;
        }
    }
    return 0;
}