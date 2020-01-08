#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int m, s, top;
char ch;

int *resizing(int *st) {
    auto *new_st = (int*) malloc((size_t) s * sizeof(int));
    for (int i = 0; i < top; i++) {
        new_st[i] = st[i];
    }
    free(st);
    return new_st;
}

int main() {
   freopen("stack.in", "r", stdin);
   freopen("stack.out", "w", stdout);
    ios_base::sync_with_stdio(0);

    cin >> m;
    s = 1; top = 0;
    auto *st = (int*) malloc((size_t) s * sizeof(int));
    for (int i = 0; i < m; i++) {
        cin >> ch;
        if (top == s) {
            s *= 2;
            st = resizing(st);
        }
        if ((s > 1) && (top * 4 <= s)) {
            s /= 2;
            st = resizing(st);
        }
        if (ch == '+') {
            cin >> st[top];
            ++top;
        } else {
            --top;
            cout << st[top] << '\n';
        }
    }
}